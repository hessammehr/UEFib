#include <stdint.h>
#include <stdbool.h>

typedef void *EFI_HANDLE;
typedef uint64_t EFI_STATUS;

char buff[64] = {'D', 0, 'A', 0, 'V', 0, 'I', 0, 'D', 0, 'E', 0, ' ', 0, 'O', 0, 'S', 0, 10, 0, 13, 0, 'f', 0, 'i', 0, 'b', 0, '(', 0, '4', 0, '6', 0, ')', 0, '=', 0, 0};
char num_buff[64];

typedef struct {
    /* table header – you can define it properly or just pad it */
    uint64_t Signature;
    uint32_t Revision;
    uint32_t HeaderSize;
    uint32_t CRC32;
    uint32_t Reserved;
} EFI_TABLE_HEADER;

typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef struct {
    EFI_STATUS (*Reset)(void *, bool);
    EFI_STATUS (*OutputString)(void *, char *);
    void *TestString;
    void *QueryMode;
    void *SetMode;
    void *SetAttribute;
    EFI_STATUS (*ClearScreen)(void *);
    void *SetCursorPosition;
    void *EnableCursor;
    void *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct _EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER Hdr;
    void *FirmwareVendor;
    uint32_t FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    void *RuntimeServices;
    void *BootServices;
    uint64_t NumberOfTableEntries;
    void *ConfigurationTable;
} EFI_SYSTEM_TABLE;

char* print_int(uint64_t num) {
    // Zero out num_buff
    for (int i=0; i<64; i++) {
        num_buff[i] = 0;
    }
    // num_buff[56] = 'a';
    // num_buff[57] = 0;
    num_buff[58] = 10;
    num_buff[59] = 0;
    num_buff[60] = 13;
    num_buff[61] = 0;
    num_buff[62] = 0;

    uint64_t pos = 56;
    while(num) {
        char dig = num % 10;
        num_buff[pos] = dig + 48;
        num_buff[pos + 1] = 0;
        num = num / 10;
        pos -= 2;
    }

    return &num_buff[pos] + 2;
}

uint64_t fib(uint64_t n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int EfiMain(void *image_handle, EFI_SYSTEM_TABLE *system_table) {
    system_table->ConOut->Reset(system_table->ConOut, 0);
    system_table->ConOut->ClearScreen(system_table->ConOut);
    system_table->ConOut->OutputString(system_table->ConOut, buff);
    system_table->ConOut->OutputString(system_table->ConOut, print_int(fib(46)));
    while(1) {

    }
    // for (uint64_t test=0; test < 100000; test++) {
    //     print_int(test);
    // }
}