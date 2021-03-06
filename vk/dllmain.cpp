// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
extern "C" {
	#include "vmulticlient.h"
}

const char _asciimap[128][2] =
{
	{0x00, 0},             // NUL
	{0x00, 0},             // SOH
	{0x00, 0},             // STX
	{0x00, 0},             // ETX
	{0x00, 0},             // EOT
	{0x00, 0},             // ENQ
	{0x00, 0},             // ACK  
	{0x00, 0},             // BEL
	{0x2a, 0},			// BS	Backspace
	{0x2b, 0},			// TAB	Tab
	{0x28, 0},			// LF	Enter
	{0x00, 0},             // VT 
	{0x00, 0},             // FF 
	{0x00, 0},             // CR 
	{0x00, 0},             // SO 
	{0x00, 0},             // SI 
	{0x00, 0},             // DEL
	{0x00, 0},             // DC1
	{0x00, 0},             // DC2
	{0x00, 0},             // DC3
	{0x00, 0},             // DC4
	{0x00, 0},             // NAK
	{0x00, 0},             // SYN
	{0x00, 0},             // ETB
	{0x00, 0},             // CAN
	{0x00, 0},             // EM 
	{0x00, 0},             // SUB
	{0x00, 0},             // ESC
	{0x00, 0},             // FS 
	{0x00, 0},             // GS 
	{0x00, 0},             // RS 
	{0x00, 0},             // US 
	{0x2c, 0},		   //  10
	{0x1e, 1}, //  | SHIFT, 0},	   // !
	{0x34, 1}, //   | SHIFT, 0},	   // "
	{0x20, 1}, //   | SHIFT, 0},    // #
	{0x21, 1}, //   | SHIFT, 0},    // $
	{0x22, 1}, //   | SHIFT, 0},    // %
	{0x24, 1}, //   | SHIFT, 0},    // &
	{0x34, 0},          // '
	{0x26, 1}, //   | SHIFT, 0},    // (
	{0x27, 1}, //   | SHIFT, 0},    // )
	{0x25, 1}, //   | SHIFT, 0},    // *
	{0x2e, 1}, //   | SHIFT, 0},    // +
	{0x36, 0},          // , 0},
	{0x2d, 0},          // -
	{0x37, 0},          // .
	{0x38, 0},          // /
	{0x27, 0},          // 0
	{0x1e, 0},          // 1
	{0x1f, 0},          // 2
	{0x20, 0},          // 3
	{0x21, 0},          // 4
	{0x22, 0},          // 5
	{0x23, 0},          // 6
	{0x24, 0},          // 7
	{0x25, 0},          // 8
	{0x26, 0},          // 9
	{0x33, 1}, //   | SHIFT, 0},      // :
	{0x33, 0},          // ,
	{0x36, 1}, //   | SHIFT, 0},      // <
	{0x2e, 0},          // =
	{0x37, 1}, //   | SHIFT, 0},      // >
	{0x38, 1}, //   | SHIFT, 0},      // ?
	{0x1f, 1}, //   | SHIFT, 0},      // @
	{0x04, 1}, //   | SHIFT, 0},      // A
	{0x05, 1}, //   | SHIFT, 0},      // B
	{0x06, 1}, //   | SHIFT, 0},      // C
	{0x07, 1}, //   | SHIFT, 0},      // D
	{0x08, 1}, //   | SHIFT, 0},      // E
	{0x09, 1}, //   | SHIFT, 0},      // F
	{0x0a, 1}, //   | SHIFT, 0},      // G
	{0x0b, 1}, //   | SHIFT, 0},      // H
	{0x0c, 1}, //   | SHIFT, 0},      // I
	{0x0d, 1}, //   | SHIFT, 0},      // J
	{0x0e, 1}, //   | SHIFT, 0},      // K
	{0x0f, 1}, //   | SHIFT, 0},      // L
	{0x10, 1}, //   | SHIFT, 0},      // M
	{0x11, 1}, //   | SHIFT, 0},      // N
	{0x12, 1}, //   | SHIFT, 0},      // O
	{0x13, 1}, //   | SHIFT, 0},      // P
	{0x14, 1}, //   | SHIFT, 0},      // Q
	{0x15, 1}, //   | SHIFT, 0},      // R
	{0x16, 1}, //   | SHIFT, 0},      // S
	{0x17, 1}, //   | SHIFT, 0},      // T
	{0x18, 1}, //   | SHIFT, 0},      // U
	{0x19, 1}, //   | SHIFT, 0},      // V
	{0x1a, 1}, //   | SHIFT, 0},      // W
	{0x1b, 1}, //   | SHIFT, 0},      // X
	{0x1c, 1}, //   | SHIFT, 0},      // Y
	{0x1d, 1}, //   | SHIFT, 0},      // Z
	{0x2f, 0},          // [
	{0x31, 0},          // bslash
	{0x30, 0},          // ]
	{0x23, 1}, //   | SHIFT, 0},    // ^
	{0x2d, 1}, //   | SHIFT, 0},    // _
	{0x35, 0},          // `
	{0x04, 0},          // a
	{0x05, 0},          // b
	{0x06, 0},          // c
	{0x07, 0},          // d
	{0x08, 0},          // e
	{0x09, 0},          // f
	{0x0a, 0},          // g
	{0x0b, 0},          // h
	{0x0c, 0},          // i
	{0x0d, 0},          // j
	{0x0e, 0},          // k
	{0x0f, 0},          // l
	{0x10, 0},          // m
	{0x11, 0},          // n
	{0x12, 0},          // o
	{0x13, 0},          // p
	{0x14, 0},          // q
	{0x15, 0},          // r
	{0x16, 0},          // s
	{0x17, 0},          // t
	{0x18, 0},          // u
	{0x19, 0},          // v
	{0x1a, 0},          // w
	{0x1b, 0},          // x
	{0x1c, 0},          // y
	{0x1d, 0},          // z
	{0x2f, 1}, //   | SHIFT, 0},    // 
	{0x31, 1}, //   | SHIFT, 0},    // |
	{0x30, 1}, //   | SHIFT, 0},    // }
	{0x35, 1}, //   | SHIFT, 0},    // ~
	{0x00, 0}				// DEL
};


VOID SendHidRequests(pvmulti_client vmulti, const char* lpszStr);

pvmulti_client Attach() {
	pvmulti_client ret = vmulti_alloc();
	if (ret) {
		if (!vmulti_connect(ret))
		{
			vmulti_free(ret);
			ret = NULL;
		}
	}
	return ret;
}

void Detach(pvmulti_client vmulti) {
	if (vmulti) {
		vmulti_disconnect(vmulti);
		vmulti_free(vmulti);	
	}
	vmulti = NULL;
} 

BOOL WINAPI InputString(const char* lpszStr)  {
	BOOL bRet = FALSE;
	pvmulti_client vmulti = Attach();
	if (vmulti) {
		SendHidRequests(vmulti, lpszStr);
		Detach(vmulti);
		bRet = TRUE;
	} 
	return bRet;
}

BOOL WINAPI InputChar(const char c)  {
	BOOL bRet = FALSE;
	if (c > 0) {
		pvmulti_client vmulti = Attach();
		if (vmulti) {
			char buf[2] = {0};
			buf[0] = c;
			SendHidRequests(vmulti, buf);
			Detach(vmulti);
			bRet = TRUE;
		}	
	} 
	return bRet;
}

VOID SendHidRequests(pvmulti_client vmulti, const char* lpszStr)
{
    BYTE shiftKeys = 0;
    BYTE keyCodes[KBD_KEY_CODES] = {0, 0, 0, 0, 0, 0};

	int len = strlen(lpszStr);
	if (len <= 0) return; 
	char last_c = 0;
	for (int i=0; i<len; i++) {
		shiftKeys = 0;
		char c = lpszStr[i] & 0x7F;
		if (c == last_c) {
		    keyCodes[0] = 0x0;
            vmulti_update_keyboard(vmulti, shiftKeys, keyCodes);
	    }
		last_c = c;
		if (_asciimap[c][1] == 1) {
			shiftKeys = KBD_LSHIFT_BIT;
		}
		keyCodes[0] = _asciimap[c][0];
		vmulti_update_keyboard(vmulti, shiftKeys, keyCodes);		
	}
	shiftKeys = 0;
	keyCodes[0] = 0x0;
    vmulti_update_keyboard(vmulti, shiftKeys, keyCodes);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		//Attach();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		//Detach();
		break;
	}
	return TRUE;
}

