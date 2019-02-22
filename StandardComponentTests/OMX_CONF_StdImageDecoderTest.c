/*
 * Copyright (c) 2019 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** OMX_CONF_StdImageDecoderTest.c
 *  OpenMax IL conformance test - Standard Image Decoder Component Test
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "OMX_CONF_StdCompCommon.h"
#include <string.h>

#define TEST_NAME_STRING "StdImageDecoderTest"

/**************************** G L O B A L S **********************************/

/*****************************************************************************/

OMX_ERRORTYPE StdImageDecoderTest_JpegDecoder(TEST_CTXTYPE *pCtx)
{
    OMX_ERRORTYPE eError = OMX_ErrorNone;
    OMX_U32 nPortIndex;

    eError = StdComponentTest_SetRole(pCtx, "image_decoder.jpeg");
    OMX_CONF_BAIL_ON_ERROR(eError);

    /* For the standard JPEG decoder component, there must be at least two image domain ports. */
    if (pCtx->sPortParamImage.nPorts < 2) eError = OMX_ErrorUndefined;
    OMX_CONF_BAIL_ON_ERROR(eError);

    /* Verify - Port Index = IPB + 0; input port, JPEG format */
    OMX_OSAL_Trace(OMX_OSAL_TRACE_INFO, "Verifying JPEG input port 0 \n");
    nPortIndex = pCtx->sPortParamImage.nStartPortNumber + 0;
    OMX_CONF_BAIL_ON_ERROR(eError);
    if (StdComponentTest_IsInputPort(pCtx, nPortIndex) == OMX_FALSE) eError = OMX_ErrorUndefined;                            
    OMX_CONF_BAIL_ON_ERROR(eError);
    eError = StdCompCommonImage_JpegPortParameters(pCtx, nPortIndex);
    OMX_CONF_BAIL_ON_ERROR(eError);

    /* Verify - Port Index = IPB + 1; output port, raw image format */
    OMX_OSAL_Trace(OMX_OSAL_TRACE_INFO, "Verifying Raw image output port 1 \n");
    nPortIndex = pCtx->sPortParamImage.nStartPortNumber + 1;
    if (StdComponentTest_IsOutputPort(pCtx, nPortIndex) == OMX_FALSE) eError = OMX_ErrorUndefined;                            
    OMX_CONF_BAIL_ON_ERROR(eError);
    eError = StdCompCommonImage_RawPortParameters(pCtx, nPortIndex);
    OMX_CONF_BAIL_ON_ERROR(eError);

OMX_CONF_TEST_BAIL:

    return (eError);
}

/*****************************************************************************/

OMX_ERRORTYPE StdImageDecoderTest_WebpDecoder(TEST_CTXTYPE *pCtx)
{
    OMX_ERRORTYPE eError = OMX_ErrorNone;
    OMX_U32 nPortIndex;

    eError = StdComponentTest_SetRole(pCtx, "image_decoder.webp");
    OMX_CONF_BAIL_ON_ERROR(eError);

    /* For the standard WEBP decoder component, there must be at least two image domain ports. */
    if (pCtx->sPortParamImage.nPorts < 2) eError = OMX_ErrorUndefined;
    OMX_CONF_BAIL_ON_ERROR(eError);

    /* Verify - Port Index = IPB + 0; input port, WEBP format */
    OMX_OSAL_Trace(OMX_OSAL_TRACE_INFO, "Verifying WEBP input port 0 \n");
    nPortIndex = pCtx->sPortParamImage.nStartPortNumber + 0;
    OMX_CONF_BAIL_ON_ERROR(eError);
    if (StdComponentTest_IsInputPort(pCtx, nPortIndex) == OMX_FALSE) eError = OMX_ErrorUndefined;                            
    OMX_CONF_BAIL_ON_ERROR(eError);
    eError = StdCompCommonImage_WebpPortParameters(pCtx, nPortIndex);
    OMX_CONF_BAIL_ON_ERROR(eError);

    /* Verify - Port Index = IPB + 1; output port, raw image format */
    OMX_OSAL_Trace(OMX_OSAL_TRACE_INFO, "Verifying Raw image output port 1 \n");
    nPortIndex = pCtx->sPortParamImage.nStartPortNumber + 1;
    if (StdComponentTest_IsOutputPort(pCtx, nPortIndex) == OMX_FALSE) eError = OMX_ErrorUndefined;                            
    OMX_CONF_BAIL_ON_ERROR(eError);
    eError = StdCompCommonImage_RawPortParameters(pCtx, nPortIndex);
    OMX_CONF_BAIL_ON_ERROR(eError);

OMX_CONF_TEST_BAIL:

    return (eError);
}

/*****************************************************************************/

/* Test a component for compliance with the Standard JPEG Decoder. */

OMX_ERRORTYPE OMX_CONF_StdJpegDecoderTest(
    OMX_IN OMX_STRING cComponentName)
{
    OMX_ERRORTYPE eError = OMX_ErrorNone;
    TEST_CTXTYPE ctx;

    eError = StdComponentTest_IsRoleSupported(cComponentName, "image_decoder.jpeg");
    OMX_CONF_BAIL_ON_ERROR(eError);

    memset(&ctx, 0x0, sizeof(TEST_CTXTYPE));

    eError = StdComponentTest_StdComp(cComponentName, &ctx,
            (STDCOMPTEST_COMPONENT)StdImageDecoderTest_JpegDecoder);

OMX_CONF_TEST_BAIL:

    return (eError);
}

/*****************************************************************************/

/* Test a component for compliance with the Standard WEBP Decoder. */

OMX_ERRORTYPE OMX_CONF_StdWebpDecoderTest(
    OMX_IN OMX_STRING cComponentName)
{
    OMX_ERRORTYPE eError = OMX_ErrorNone;
    TEST_CTXTYPE ctx;

    eError = StdComponentTest_IsRoleSupported(cComponentName, "image_decoder.webp");
    OMX_CONF_BAIL_ON_ERROR(eError);

    memset(&ctx, 0x0, sizeof(TEST_CTXTYPE));

    eError = StdComponentTest_StdComp(cComponentName, &ctx,
            (STDCOMPTEST_COMPONENT)StdImageDecoderTest_WebpDecoder);

OMX_CONF_TEST_BAIL:

    return (eError);
}

/*****************************************************************************/

/* This runs through and tests all standard components of the image decoder class
   exposed and supported by the component.
*/
OMX_ERRORTYPE OMX_CONF_StdImageDecoderTest(
    OMX_IN OMX_STRING cComponentName)
{
    OMX_ERRORTYPE eError = OMX_ErrorNone;

    OMX_U32 nNumRoles;
    OMX_STRING sRoles[MAX_COMPONENT_ROLES] = {NULL};
    OMX_U32 i;

    /* The following utility function calls OMX_GetRolesOfComponent,
       allocates memory, and populates strings.
    */
    eError = StdComponentTest_PopulateRolesArray(cComponentName, &nNumRoles, sRoles);
    OMX_CONF_BAIL_ON_ERROR(eError);

    eError = OMX_ErrorComponentNotFound;
    for (i = 0; i < nNumRoles; i++)
    {
        if (strstr(sRoles[i], "image_decoder.jpeg") != NULL) {
            eError = OMX_CONF_StdJpegDecoderTest(cComponentName);
        }
        else if (strstr(sRoles[i], "image_decoder.webp") != NULL) {
            eError = OMX_CONF_StdWebpDecoderTest(cComponentName);
        }
        else {
            continue;
        }
        OMX_CONF_BAIL_ON_ERROR(eError);
    }
    
OMX_CONF_TEST_BAIL:
    StdComponentTest_FreeRolesArray(nNumRoles, sRoles);
    return (eError);
}

/*****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/* File EOF */

