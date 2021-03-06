#
# Script to install CppUTest binary libraries in AppVeyor
#

# Load functions from the helper file
. (Join-Path (Split-Path $MyInvocation.MyCommand.Path) 'appveyor_helpers.ps1')

Start-FileDownload 'https://github.com/jgonzalezdr/cpputest/releases/download/v4.0-gdr0/cpputest-4.0-gdr0.txz'
New-Item -ItemType Directory -Force -Path "$env:CPPUTEST_HOME" | Out-Null
Invoke-Command "tar -Jxvf cpputest-4.0-gdr0.txz -C $env:CPPUTEST_HOME" | Out-Null
