/* Expression parsing for plural form selection.
   Copyright (C) 2000-2013 Free Software Foundation, Inc.
   Written by Ulrich Drepper <drepper@cygnus.com>, 2000.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include "windows_.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "plural-exp.h"
#include "eval-plural.h"
#undef strstr

/* These structs are the constant expression for the germanic plural
   form determination.  It represents the expression  "n != 1".  */
static struct expression plvar = {
	0,
	var,
	{ { NULL, NULL, NULL }, 0 }
};

static struct expression plone = {
	0,
	num,
	{ { NULL, NULL, NULL }, 1 }
};

const struct expression GERMANIC_PLURAL = {
	2,									/* nargs */
	not_equal,							/* operation */
	{ { &plvar, &plone, NULL }, 0 }
};

void EXTRACT_PLURAL_EXPRESSION(const char *nullentry, const struct expression **pluralp, unsigned long int *npluralsp)
{
	if (nullentry != NULL)
	{
		const char *plural;
		const char *nplurals;

		plural = strstr(nullentry, "plural=");
		nplurals = strstr(nullentry, "nplurals=");
		if (plural == NULL || nplurals == NULL)
			goto no_plural;
		else
		{
			const char *endp;
			unsigned long int n;
			struct parse_args args;

			/* First get the number.  */
			nplurals += 9;
			while (*nplurals != '\0' && isspace((unsigned char) *nplurals))
				++nplurals;
			if (!(*nplurals >= '0' && *nplurals <= '9'))
				goto no_plural;
			for (endp = nplurals, n = 0; *endp >= '0' && *endp <= '9'; endp++)
				n = n * 10 + (*endp - '0');
			if (nplurals == endp)
				goto no_plural;
			*npluralsp = n;

			/* Due to the restrictions bison imposes onto the interface of the
			   scanner function we have to put the input string and the result
			   passed up from the parser into the same structure which address
			   is passed down to the parser.  */
			plural += 7;
			args.cp = plural;
			if (PLURAL_PARSE(&args) != 0)
				goto no_plural;
			*pluralp = args.res;
		}
	} else
	{
		/* By default we are using the Germanic form: singular form only
		   for `one', the plural form otherwise.  Yes, this is also what
		   English is using since English is a Germanic language.  */
	  no_plural:
		*pluralp = &GERMANIC_PLURAL;
		*npluralsp = 2;
	}
}