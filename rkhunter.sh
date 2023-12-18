#!/bin/sh
(
/usr/local/bin/rkhunter –versioncheck
/usr/local/bin/rkhunter –update --propupd
/usr/local/bin/rkhunter –cronjob –report-warnings-only
) | /bin/mail -s "rkhunter Daily Run '$HOSTNAME'" infradevsys@nic.br
