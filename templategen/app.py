#!/usr/bin/env python
"""Generate source code from a given template."""

import argparse
import datetime
import os.path
import re
import string
import sys

from .utils import (create_config_if_missing, get_global_mapping,
                    get_template_dir, list_templates, write_file)


def generate_target_filepath(target_dirpath, name, template_file):
    """Generate the target filepath."""
    file_extension = os.path.splitext(template_file)[1]
    filepath = os.path.join(target_dirpath, str(name) + file_extension)
    return filepath


def generate_template_filepath(template_name, template_file):
    """Generate the target filepath."""
    template_dirpath = get_template_dir(template_name)
    filepath = os.path.join(template_dirpath, template_file)
    return filepath


def get_template_files(template_name):
    """Get a list with the names of all template files."""
    template_dirpath = get_template_dir(template_name)
    template_files = os.listdir(template_dirpath)
    return template_files


def get_mapping(name):
    """Get the mapping."""
    now = datetime.date.today()
    default_mapping = {
        "name": name,
        "NAME": name.upper(),
        "date": now,
        "year": now.year
    }
    global_mapping = get_global_mapping()
    merged_mapping = {**default_mapping, **global_mapping}

    return merged_mapping


def generate(name, template_name, target_dirpath):
    """Generate files from a template."""
    template_files = get_template_files(template_name)
    for template_file in template_files:

        target_filepath = generate_target_filepath(target_dirpath, name,
                                                   template_file)
        if os.path.isfile(target_filepath):
            print(f"Target file '{target_filepath}' already exists")
            sys.exit(1)

        template_filepath = generate_template_filepath(template_name,
                                                       template_file)
        try:
            with open(template_filepath, 'r', encoding='utf-8') as file:
                # -------------------------------------------------------------
                # Populate template
                file_contents = file.read()
                template_text = string.Template((file_contents))
                merged_mapping = get_mapping(name)
                result_output = template_text.safe_substitute(**merged_mapping)

                # -------------------------------------------------------------
                # Check remaining placeholders
                placeholders = set(re.findall(r'\$\{(\w+)\}', result_output))
                # placeholders = template_text.get_identifiers()
                if len(placeholders) != 0:
                    print("Please configure the remaining placeholders")
                    for placeholder in placeholders:
                        print(f"Placeholder: '{placeholder}'")
                    sys.exit(1)

                # -------------------------------------------------------------
                # Write
                write_file(target_filepath, result_output)

        except FileNotFoundError:
            print(f"Template file '{template_filepath}' does not exist")
            sys.exit(1)


def app_run():
    """Entry point for the app."""
    # -------------------------------------------------------------------------
    # Prepare
    create_config_if_missing()

    # -------------------------------------------------------------------------
    # Arguments
    templates = list_templates()

    parser = argparse.ArgumentParser(
        description='Source code template generator')
    parser.add_argument('-n',
                        '--name',
                        required=True,
                        help='The name of the new module.')
    parser.add_argument('-p',
                        '--path',
                        default=".",
                        help='The path of the new generated file[s].')
    parser.add_argument('-t',
                        '--template',
                        default="c",
                        help=f"The name of the template to use. {templates}")
    args = parser.parse_args()

    # Cli arguments
    name = args.name
    target_dirpath = os.path.abspath(args.path)
    template_name = args.template

    # -------------------------------------------------------------------------
    # Generate

    generate(name, template_name, target_dirpath)


if __name__ == "__main__":
    app_run()
