#include <array>
#include <cstring>
#include <iostream>
#include <vector>

#include <d3d9.h>

#include "../common/com.h"
#include "../common/error.h"
#include "../common/str.h"

Com<IDirect3D9Ex>         m_d3d;
Com<IDirect3DDevice9Ex>   m_device;

using namespace std;

int main() {

		// std::cout << "loading d3d9.dll " << std::endl;
	// HMODULE hD3D9 = LoadLibraryA("d3d9.dll");
	// if (!hD3D9)
		// throw Error("Failed to load D3D9 library");

	// auto pDirect3DCreate9Ex = (decltype(Direct3DCreate9Ex)*)GetProcAddress(hD3D9, "Direct3DCreate9Ex");

	// if (pDirect3DCreate9Ex == 0)
	// 	throw Error("Failed to get Direct3DCreate9Ex proc address");

	IDirect3D9Ex* pD3D9 = nullptr;
	// HRESULT status = pDirect3DCreate9Ex(D3D_SDK_VERSION, &pD3D9);

    HRESULT status = Direct3DCreate9Ex(D3D_SDK_VERSION, &pD3D9);

	if (FAILED(status))
		throw Error("Failed to create D3D9 interface");

	D3DADAPTER_IDENTIFIER9 d3dID;

	// Get the identifier for the default adapter (adapter 0)
	if (SUCCEEDED(pD3D9->GetAdapterIdentifier(D3DADAPTER_DEFAULT, 0, &d3dID))) {
		// The Description field contains the device name
		std::cout << "Device Name: " << d3dID.Description << std::endl;
		// The DeviceName field contains the Windows display device name (e.g., "\\.\DISPLAY1")
		// std::cout << "Device Path: " << d3dID.DeviceName << std::endl;
	} else {
		std::cerr << "Failed to get adapter identifier." << std::endl;
	}

	// UINT adapter = D3DADAPTER_DEFAULT;

	// D3DADAPTER_IDENTIFIER9 adapterId;
	// m_d3d->GetAdapterIdentifier(adapter, 0, &adapterId);

	// std::cout << format("Using adapter: ", adapterId.Description) << std::endl;

	return 0;
}
