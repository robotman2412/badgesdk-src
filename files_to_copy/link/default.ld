PHDRS
{
	codeseg PT_LOAD;
	rodataseg PT_LOAD;
	dataseg PT_LOAD;
	dynseg PT_DYNAMIC;
}

SECTIONS
{
	/* Origin is different than usual */
	. = 0x00010000;
	
	/* Code sections. */
	.text   : { *(.text) *(.text*) } :codeseg
	
	/* Read-only data sections. */
	.init_array : {
		/* Create symbols to keep track of `.init_array`. */
		__start_init_array = .;
		KEEP(*(.init_array))
		__stop_init_array = .;
	} :rodataseg
	.rodata : { *(.rodata) *(.rodata*) } :rodataseg
	
	/* Dynamic linking information. */
	.dynamic  : { KEEP(*(.dynamic)) } :dynseg :dataseg
	.dynstr   : { KEEP(*(.dynstr)) }
	.rela.dyn : { KEEP(*(.rela.dyn)) }
	
	/* Data sections. */
	.data   : { *(.data) *(.data*) } :dataseg
	.bss    : { *(.bss) *(.bss*) }
}

/*
	Set the entry vector to _start.
	Note that in this ABI, _start is a function taking `int argc, char **argv, char **envp`.
	The exit code is passed when `_exit(int code)` is called.
*/
ENTRY(_start)
