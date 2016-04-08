import sys
import os
import shlex
import subprocess

read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

if read_the_docs_build:
    subprocess.call('doxygen', shell=True)

extensions = ['breathe']
breathe_projects = { 'SegmentDisplay': 'xml' }
breathe_default_project = "SegmentDisplay"
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
project = u'6-digit-7-Segment-Arduino'
copyright = u'2016, 6-digit-7-Segment-Arduino'
author = u'6-digit-7-Segment-Arduino'
version = '1.0'
release = '1.0'
language = None
exclude_patterns = ['_build']
pygments_style = 'sphinx'
todo_include_todos = False
html_static_path = ['_static']
htmlhelp_basename = '6-digit-7-Segment-Arduinodoc'
latex_elements = {
}
latex_documents = [
  (master_doc, '6-digit-7-Segment-Arduino.tex', u'6-digit-7-Segment-Arduino Documentation',
   u'6-digit-7-Segment-Arduino', 'manual'),
]
