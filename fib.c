#include <stdint.h>
#include <stdbool.h>

typedef void *EFI_HANDLE;
typedef uint64_t EFI_STATUS;

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

char buff[32] = {'D', 0, 'A', 0, 'V', 0, 'I', 0, 'D', 0, 'E', 0, 0};

int EfiMain(void *image_handle, EFI_SYSTEM_TABLE *system_table) {
    system_table->ConOut->Reset(system_table->ConOut, 0);
    system_table->ConOut->ClearScreen(system_table->ConOut);
    system_table->ConOut->OutputString(system_table->ConOut, buff);
    while(1) {

    }
}