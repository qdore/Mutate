#
# Regular cron jobs for the mutate package
#
0 4	* * *	root	[ -x /usr/bin/mutate_maintenance ] && /usr/bin/mutate_maintenance
