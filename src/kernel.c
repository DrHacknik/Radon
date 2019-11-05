/*
=====================================================================================
= Dr.Hacknik 2019 - Radon Kernel - Licensed under the GNU LGPLv3 License Agreement  =
=====================================================================================
*/

void main(void)
{
	const char *tst = "This is a test kernel";
	/* video memory begins at address 0xb8000 */
	char *vidptr = (char*)0xb8000;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int screensize;

	/* this loops clears the screen
	* there are 25 lines each of 80 columns; each element takes 2 bytes */
	screensize = 80 * 25 * 2;
	while (j < screensize) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte */
		vidptr[j+1] = 0x07;
		j = j + 2;
	}

	j = 0;

	/* this loop writes the string to video memory */
	while (tst[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = tst[j];
		/* attribute-byte: give character black bg and light grey fg */
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}