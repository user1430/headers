typedef struct _NDIS_OBJECT_HEADER
{
  /* 0x0000 */ unsigned char Type;
  /* 0x0001 */ unsigned char Revision;
  /* 0x0002 */ unsigned short Size;
} NDIS_OBJECT_HEADER, *PNDIS_OBJECT_HEADER; /* size: 0x0004 */

typedef struct _NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS
{
  /* 0x0000 */ struct _NDIS_OBJECT_HEADER Header;
  /* 0x0004 */ unsigned long Reserved;
  /* 0x0008 */ void* CmCreateVcHandler /* function */;
  /* 0x000c */ void* CmDeleteVcHandler /* function */;
  /* 0x0010 */ void* CmOpenAfHandler /* function */;
  /* 0x0014 */ void* CmCloseAfHandler /* function */;
  /* 0x0018 */ void* CmRegisterSapHandler /* function */;
  /* 0x001c */ void* CmDeregisterSapHandler /* function */;
  /* 0x0020 */ void* CmMakeCallHandler /* function */;
  /* 0x0024 */ void* CmCloseCallHandler /* function */;
  /* 0x0028 */ void* CmIncomingCallCompleteHandler /* function */;
  /* 0x002c */ void* CmAddPartyHandler /* function */;
  /* 0x0030 */ void* CmDropPartyHandler /* function */;
  /* 0x0034 */ void* CmActivateVcCompleteHandler /* function */;
  /* 0x0038 */ void* CmDeactivateVcCompleteHandler /* function */;
  /* 0x003c */ void* CmModifyCallQoSHandler /* function */;
  /* 0x0040 */ void* CmOidRequestHandler /* function */;
  /* 0x0044 */ void* CmOidRequestCompleteHandler /* function */;
  /* 0x0048 */ void* CmNotifyCloseAfCompleteHandler /* function */;
} NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS, *PNDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS; /* size: 0x004c */

