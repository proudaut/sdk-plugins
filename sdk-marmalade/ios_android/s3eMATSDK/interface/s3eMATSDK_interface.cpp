/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eMATSDK.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*s3eStartMobileAppTracker_t)(const char* adId, const char* adKey);
typedef       void(*s3eSDKParameters_t)();
typedef       void(*s3eTrackInstall_t)();
typedef       void(*s3eTrackUpdate_t)();
typedef       void(*s3eTrackInstallWithReferenceId_t)(const char* refId);
typedef       void(*s3eTrackActionForEventIdOrName_t)(const char* eventIdOrName, bool isId, const char* refId);
typedef       void(*s3eTrackActionForEventIdOrNameItems_t)(const char* eventIdOrName, bool isId, const s3eMATArray* items, const char* refId, double revenueAmount, const char* currencyCode, uint8 transactionState);
typedef       void(*s3eTrackAction_t)(const char* eventIdOrName, bool isId, double revenue, const char* currency);
typedef       void(*s3eStartAppToAppTracking_t)(const char* targetAppId, const char* advertiserId, const char* offerId, const char* publisherId, bool shouldRedirect);
typedef       void(*s3eSetPackageName_t)(const char* packageName);
typedef       void(*s3eSetCurrencyCode_t)(const char* currencyCode);
typedef       void(*s3eSetDeviceId_t)(const char* deviceId);
typedef       void(*s3eSetOpenUDID_t)(const char* openUDID);
typedef       void(*s3eSetUserId_t)(const char* userId);
typedef       void(*s3eSetRevenue_t)(double revenue);
typedef       void(*s3eSetSiteId_t)(const char* siteId);
typedef       void(*s3eSetTRUSTeId_t)(const char* tpid);
typedef       void(*s3eSetDelegate_t)(bool enable);
typedef       void(*s3eSetUseHTTPS_t)(bool enable);
typedef       void(*s3eSetAllowDuplicates_t)(bool allowDuplicates);
typedef       void(*s3eSetShouldAutoGenerateMacAddress_t)(bool shouldAutoGenerate);
typedef       void(*s3eSetShouldAutoGenerateODIN1Key_t)(bool shouldAutoGenerate);
typedef       void(*s3eSetShouldAutoGenerateOpenUDIDKey_t)(bool shouldAutoGenerate);
typedef       void(*s3eSetShouldAutoGenerateVendorIdentifier_t)(bool shouldAutoGenerate);
typedef       void(*s3eSetShouldAutoGenerateAdvertiserIdentifier_t)(bool shouldAutoGenerate);
typedef       void(*s3eSetUseCookieTracking_t)(bool useCookieTracking);
typedef       void(*s3eSetRedirectUrl_t)(const char* redirectUrl);
typedef       void(*s3eSetAdvertiserIdentifier_t)(const char* advertiserId);
typedef       void(*s3eSetVendorIdentifier_t)(const char* vendorId);
typedef       void(*s3eSetDebugResponse_t)(bool shouldDebug);

/**
 * struct that gets filled in by s3eMATSDKRegister
 */
typedef struct s3eMATSDKFuncs
{
    s3eStartMobileAppTracker_t m_s3eStartMobileAppTracker;
    s3eSDKParameters_t m_s3eSDKParameters;
    s3eTrackInstall_t m_s3eTrackInstall;
    s3eTrackUpdate_t m_s3eTrackUpdate;
    s3eTrackInstallWithReferenceId_t m_s3eTrackInstallWithReferenceId;
    s3eTrackActionForEventIdOrName_t m_s3eTrackActionForEventIdOrName;
    s3eTrackActionForEventIdOrNameItems_t m_s3eTrackActionForEventIdOrNameItems;
    s3eTrackAction_t m_s3eTrackAction;
    s3eStartAppToAppTracking_t m_s3eStartAppToAppTracking;
    s3eSetPackageName_t m_s3eSetPackageName;
    s3eSetCurrencyCode_t m_s3eSetCurrencyCode;
    s3eSetDeviceId_t m_s3eSetDeviceId;
    s3eSetOpenUDID_t m_s3eSetOpenUDID;
    s3eSetUserId_t m_s3eSetUserId;
    s3eSetRevenue_t m_s3eSetRevenue;
    s3eSetSiteId_t m_s3eSetSiteId;
    s3eSetTRUSTeId_t m_s3eSetTRUSTeId;
    s3eSetDelegate_t m_s3eSetDelegate;
    s3eSetUseHTTPS_t m_s3eSetUseHTTPS;
    s3eSetAllowDuplicates_t m_s3eSetAllowDuplicates;
    s3eSetShouldAutoGenerateMacAddress_t m_s3eSetShouldAutoGenerateMacAddress;
    s3eSetShouldAutoGenerateODIN1Key_t m_s3eSetShouldAutoGenerateODIN1Key;
    s3eSetShouldAutoGenerateOpenUDIDKey_t m_s3eSetShouldAutoGenerateOpenUDIDKey;
    s3eSetShouldAutoGenerateVendorIdentifier_t m_s3eSetShouldAutoGenerateVendorIdentifier;
    s3eSetShouldAutoGenerateAdvertiserIdentifier_t m_s3eSetShouldAutoGenerateAdvertiserIdentifier;
    s3eSetUseCookieTracking_t m_s3eSetUseCookieTracking;
    s3eSetRedirectUrl_t m_s3eSetRedirectUrl;
    s3eSetAdvertiserIdentifier_t m_s3eSetAdvertiserIdentifier;
    s3eSetVendorIdentifier_t m_s3eSetVendorIdentifier;
    s3eSetDebugResponse_t m_s3eSetDebugResponse;
} s3eMATSDKFuncs;

static s3eMATSDKFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xbb39d6f4, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eMATSDK");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xbb39d6f4, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eMATSDKAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void s3eStartMobileAppTracker(const char* adId, const char* adKey)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[0] func: s3eStartMobileAppTracker"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eStartMobileAppTracker(adId, adKey);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSDKParameters()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[1] func: s3eSDKParameters"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSDKParameters();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eTrackInstall()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[2] func: s3eTrackInstall"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eTrackInstall();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eTrackUpdate()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[3] func: s3eTrackUpdate"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eTrackUpdate();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eTrackInstallWithReferenceId(const char* refId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[4] func: s3eTrackInstallWithReferenceId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eTrackInstallWithReferenceId(refId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eTrackActionForEventIdOrName(const char* eventIdOrName, bool isId, const char* refId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[5] func: s3eTrackActionForEventIdOrName"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eTrackActionForEventIdOrName(eventIdOrName, isId, refId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eTrackActionForEventIdOrNameItems(const char* eventIdOrName, bool isId, const s3eMATArray* items, const char* refId, double revenueAmount, const char* currencyCode, uint8 transactionState)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[6] func: s3eTrackActionForEventIdOrNameItems"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eTrackActionForEventIdOrNameItems(eventIdOrName, isId, items, refId, revenueAmount, currencyCode, transactionState);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eTrackAction(const char* eventIdOrName, bool isId, double revenue, const char* currency)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[7] func: s3eTrackAction"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eTrackAction(eventIdOrName, isId, revenue, currency);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eStartAppToAppTracking(const char* targetAppId, const char* advertiserId, const char* offerId, const char* publisherId, bool shouldRedirect)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[8] func: s3eStartAppToAppTracking"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eStartAppToAppTracking(targetAppId, advertiserId, offerId, publisherId, shouldRedirect);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetPackageName(const char* packageName)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[9] func: s3eSetPackageName"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetPackageName(packageName);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetCurrencyCode(const char* currencyCode)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[10] func: s3eSetCurrencyCode"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetCurrencyCode(currencyCode);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetDeviceId(const char* deviceId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[11] func: s3eSetDeviceId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetDeviceId(deviceId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetOpenUDID(const char* openUDID)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[12] func: s3eSetOpenUDID"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetOpenUDID(openUDID);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetUserId(const char* userId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[13] func: s3eSetUserId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetUserId(userId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetRevenue(double revenue)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[14] func: s3eSetRevenue"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetRevenue(revenue);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetSiteId(const char* siteId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[15] func: s3eSetSiteId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetSiteId(siteId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetTRUSTeId(const char* tpid)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[16] func: s3eSetTRUSTeId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetTRUSTeId(tpid);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetDelegate(bool enable)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[17] func: s3eSetDelegate"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetDelegate(enable);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetUseHTTPS(bool enable)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[18] func: s3eSetUseHTTPS"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetUseHTTPS(enable);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetAllowDuplicates(bool allowDuplicates)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[19] func: s3eSetAllowDuplicates"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetAllowDuplicates(allowDuplicates);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetShouldAutoGenerateMacAddress(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[20] func: s3eSetShouldAutoGenerateMacAddress"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetShouldAutoGenerateMacAddress(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetShouldAutoGenerateODIN1Key(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[21] func: s3eSetShouldAutoGenerateODIN1Key"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetShouldAutoGenerateODIN1Key(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetShouldAutoGenerateOpenUDIDKey(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[22] func: s3eSetShouldAutoGenerateOpenUDIDKey"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetShouldAutoGenerateOpenUDIDKey(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetShouldAutoGenerateVendorIdentifier(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[23] func: s3eSetShouldAutoGenerateVendorIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetShouldAutoGenerateVendorIdentifier(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetShouldAutoGenerateAdvertiserIdentifier(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[24] func: s3eSetShouldAutoGenerateAdvertiserIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetShouldAutoGenerateAdvertiserIdentifier(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetUseCookieTracking(bool useCookieTracking)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[25] func: s3eSetUseCookieTracking"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetUseCookieTracking(useCookieTracking);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetRedirectUrl(const char* redirectUrl)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[26] func: s3eSetRedirectUrl"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetRedirectUrl(redirectUrl);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetAdvertiserIdentifier(const char* advertiserId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[27] func: s3eSetAdvertiserIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetAdvertiserIdentifier(advertiserId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetVendorIdentifier(const char* vendorId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[28] func: s3eSetVendorIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetVendorIdentifier(vendorId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eSetDebugResponse(bool shouldDebug)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[29] func: s3eSetDebugResponse"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eSetDebugResponse(shouldDebug);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
