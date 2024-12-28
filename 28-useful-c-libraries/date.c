#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t calendar = time(NULL);

	struct tm *time_data;

	const char *days[] = { "Sunday",   "Monday",   "Tuesday",
			       "Wendsday", "Thursday", "Friday" };
	const char *months[] = { "Jan", "Feb", "Mar",  "Apr", "May", "Jun",
				 "Jul", "Aug", "Sept", "Oct", "Nov", "Dec" };

	time_data = localtime(&calendar);

	printf("Today is %s %s %d %d\n", days[time_data->tm_wday],
	       months[time_data->tm_mon], time_data->tm_mday,
	       time_data->tm_year + 1900);

	const char *suffix[] = { "st", "nd", "rd", "th" };

	enum sufindex { st, nd, rd, th } sufsel = th;

	struct tm birthday = { 0 };
	char name[30] = { '\0' };

	printf("Enter a name: ");
	scanf("%s", name);

	printf("Enter the birthday as day month year");
	scanf("%d %d %d", &birthday.tm_mday, &birthday.tm_mon,
	      &birthday.tm_year);

	birthday.tm_mon -= 1;
	birthday.tm_year -= 1900;

	if (mktime(&birthday) == -1) {
		fprintf(stderr, "operation failed.\n");
		return -1;
	}

	switch (birthday.tm_mday) {
	case 1:
	case 21:
	case 31:
		sufsel = st;
		break;
	case 2:
	case 22:
		sufsel = nd;
		break;
	case 3:
	case 23:
		sufsel = rd;
		break;
	default:
		sufsel = th;
		break;
	}
	printf("%s was born on the %d%s %d %d, which was a %s.\n", name,
	       birthday.tm_mday, suffix[sufsel], birthday.tm_mon,
	       (birthday.tm_year + 1900), days[birthday.tm_wday]);

	return 0;
}
