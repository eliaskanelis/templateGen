#!/usr/bin/env python
"""Utilities."""

import json
import os
import shutil
import sys

from xdg import BaseDirectory


def get_name():
    """Return the name of the package."""
    return "templategen"


def get_config_dir():
    """Return the configuration directory."""
    config_dir = os.path.join(BaseDirectory.xdg_config_home, get_name())
    return config_dir


def get_static_dir():
    """Return the static directory."""
    resourse_py_path = os.path.dirname(os.path.abspath(__file__))
    static_dir = os.path.abspath(os.path.join(resourse_py_path, "../static"))
    return static_dir


def create_config_if_missing():
    """Create the configuration directory if it does not exist."""
    # -------------------------------------------------------------------------
    # Check config directory
    config_dir = get_config_dir()

    if not os.path.exists(config_dir):
        print("Config dir does not exist")

        # ---------------------------------------------------------------------
        # Generate configs
        static_dir = get_static_dir()

        print("Populating configs")
        shutil.copytree(static_dir, config_dir)

        print("Please try again")
        sys.exit(1)


def get_template_dir(template_name):
    """Get the custom template directory."""
    config_dir = get_config_dir()
    template_dirpath = os.path.join(config_dir, "templates", template_name)
    return template_dirpath


def get_global_mapping():
    """Get the global mapping."""
    config_dir = get_config_dir()
    global_config_filepath = os.path.join(config_dir, "config.json")

    global_mapping = {}
    try:
        with open(global_config_filepath, 'r', encoding='utf-8') as file:
            global_mapping = json.load(file)
    except FileNotFoundError:
        print("File not found.")
        sys.exit(1)
    except json.JSONDecodeError:
        print("Invalid JSON data.")
        sys.exit(1)

    return global_mapping


def write_file(filepath, contents):
    """Write contents to a file."""
    try:
        with open(filepath, 'w', encoding='utf-8') as file:
            file.write(contents)
    except FileNotFoundError:
        print(f"Could not create '{filepath}': directory does not exist")
        sys.exit(1)
    except PermissionError:
        print(f"Could not create '{filepath}': permission denied")
        sys.exit(1)


def list_templates():
    """Return a list with all available templates."""
    config_dir = get_config_dir()
    template_dir = os.path.join(config_dir, "templates")

    template_list = [
        name for name in os.listdir(template_dir)
        if os.path.isdir(os.path.join(template_dir, name))
    ]
    return template_list
