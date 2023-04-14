#!/usr/bin/env python

"""Setup config for the project."""

import os

from setuptools import setup

here = os.path.abspath(os.path.dirname(__file__))

# -----------------------------------------------------------------------------


def list_all_files_recursively(dirpath):
    """List all files recursively in the directory."""
    filepath_list = list()
    for parent_path, _, filenames in os.walk(dirpath):
        for filename in filenames:
            filepath = os.path.join(parent_path, filename)
            filepath_list.append(filepath)

    return filepath_list


# -----------------------------------------------------------------------------

# Package name
packageName = "templategen"

# Load information needed by setup
about = {}
with open(os.path.join(here, f"{packageName}/__init__.py"),
          'r',
          encoding='utf-8') as f:
    exec(f.read(), about)

# Long description
with open(os.path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

# Requirements
with open("requirements.txt") as f:
    dependencies = [line for line in f if "==" in line]
    dependencies = [s.rstrip() for s in dependencies]

# -----------------------------------------------------------------------------
# Setup config
setup(
    use_scm_version=True,
    setup_requires=['setuptools_scm'],
    name=packageName,
    packages=[packageName],
    version=about['__version__'],
    license=about['__license__'],
    description='Souce code generator from a given template',
    long_description=long_description,
    long_description_content_type='text/markdown',
    author=about['__author__'],
    author_email=about['__email__'],
    url=f"https://github.com/TediCreations/{packageName}",
    download_url=f"https://github.com/TediCreations/{packageName}/archive/" +
    about['__version__'] + '.tar.gz',
    keywords=['build', 'make', 'util'],
    install_requires=dependencies,
    package_data={
        f"{packageName}": [
            "../" + filepath
            for filepath in list_all_files_recursively('static/')
        ]
    },
    include_package_data=True,
    entry_points={
        "console_scripts": [
            f"templategen = {packageName}.app:app_run",
        ]
    },
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'Topic :: Software Development :: Build Tools',
        'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.6',
    ],
)
