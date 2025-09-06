<!-- @page page_building-sdk_index Generating solutions for the FidelityFX SDK -->

To simply bulid the FidelityFX SDK _without_ building the samples, open your favorite terminal and enter the following commands:

```
cd sdk
mkdir build
cd build
cmake .. -DFFX_API_BACKEND=VK_X64 -DFFX_ALL=ON -DFFX_AUTO_COMPILE_SHADERS=1
cmake --build ./ --config Release --parallel 22
```
