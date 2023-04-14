#!/usr/bin/env python
"""Init the package."""

import sys

try:
    from pkg_resources import DistributionNotFound, get_distribution
except (ImportError, DistributionNotFound) as e:
    print(e)
    sys.exit(1)

try:
    __version__ = get_distribution(__name__).version
except DistributionNotFound:
    __version__ = "Unknown"

__author__ = "Kanelis Elias"
__email__ = "hkanelhs@yahoo.gr"
__license__ = "MIT"
