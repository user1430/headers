typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned char Type;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char Wake : 1; /* bit position: 1 */
          /* 0x0001 */ unsigned char EncodedTolerableDelay : 6; /* bit position: 2 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char Abandoned;
        struct
        {
          /* 0x0001 */ unsigned char Signalling;
          union
          {
            /* 0x0002 */ unsigned char ThreadControlFlags;
            struct /* bitfield */
            {
              /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 0 */
              /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 1 */
              /* 0x0002 */ unsigned char GroupScheduling : 1; /* bit position: 2 */
              /* 0x0002 */ unsigned char AffinitySet : 1; /* bit position: 3 */
              /* 0x0002 */ unsigned char Reserved : 4; /* bit position: 4 */
            }; /* bitfield */
            /* 0x0002 */ unsigned char Hand;
            struct
            {
              /* 0x0002 */ unsigned char Size;
              union
              {
                /* 0x0003 */ unsigned char TimerMiscFlags;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char Index : 1; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Processor : 5; /* bit position: 1 */
                  /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
                  /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DebugActive;
                /* 0x0003 */ unsigned char DpcActive;
              }; /* size: 0x0001 */
            }; /* size: 0x0002 */
          }; /* size: 0x0002 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    /* 0x0000 */ volatile long Lock;
    /* 0x0000 */ long LockNV;
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0010 */

typedef union _ULARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ unsigned long HighPart;
    }; /* size: 0x0008 */
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ unsigned long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ unsigned __int64 QuadPart;
  }; /* size: 0x0008 */
} ULARGE_INTEGER, *PULARGE_INTEGER; /* size: 0x0008 */

typedef struct _KTIMER
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
  /* 0x0010 */ union _ULARGE_INTEGER DueTime;
  /* 0x0018 */ struct _LIST_ENTRY TimerListEntry;
  /* 0x0020 */ struct _KDPC* Dpc;
  /* 0x0024 */ unsigned long Period;
} KTIMER, *PKTIMER; /* size: 0x0028 */

typedef struct _KDPC
{
  /* 0x0000 */ unsigned char Type;
  /* 0x0001 */ unsigned char Importance;
  /* 0x0002 */ volatile unsigned short Number;
  /* 0x0004 */ struct _LIST_ENTRY DpcListEntry;
  /* 0x000c */ void* DeferredRoutine /* function */;
  /* 0x0010 */ void* DeferredContext;
  /* 0x0014 */ void* SystemArgument1;
  /* 0x0018 */ void* SystemArgument2;
  /* 0x001c */ void* DpcData;
} KDPC, *PKDPC; /* size: 0x0020 */

typedef struct _NDIS_TIMER
{
  /* 0x0000 */ struct _KTIMER Timer;
  /* 0x0028 */ struct _KDPC Dpc;
} NDIS_TIMER, *PNDIS_TIMER; /* size: 0x0048 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0010 */

typedef struct _NDIS_WORK_ITEM
{
  /* 0x0000 */ void* Context;
  /* 0x0004 */ void* Routine /* function */;
  /* 0x0008 */ unsigned char WrapperReserved[32];
} NDIS_WORK_ITEM, *PNDIS_WORK_ITEM; /* size: 0x0028 */

typedef struct _WORK_QUEUE_ITEM
{
  /* 0x0000 */ struct _LIST_ENTRY List;
  /* 0x0008 */ void* WorkerRoutine /* function */;
  /* 0x000c */ void* Parameter;
} WORK_QUEUE_ITEM, *PWORK_QUEUE_ITEM; /* size: 0x0010 */

typedef struct _NDIS_IRP_WORK_ITEM
{
  /* 0x0000 */ struct _WORK_QUEUE_ITEM Item;
  /* 0x0010 */ struct _NDIS_MINIPORT_BLOCK* Miniport;
  /* 0x0014 */ struct _IRP* Irp;
} NDIS_IRP_WORK_ITEM, *PNDIS_IRP_WORK_ITEM; /* size: 0x0018 */

typedef struct _NDIS_SS_IDLE_FLAGS
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long TimerRunning : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long IdleWorkItemScheduled : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned long IdleRequestSubmitted : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned long SuspendPowerIrpRequested : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned long DeviceSuspended : 1; /* bit position: 4 */
      /* 0x0000 */ unsigned long ResumePowerIrpRequested : 1; /* bit position: 5 */
      /* 0x0000 */ unsigned long CancelWorkItemScheduled : 1; /* bit position: 6 */
      /* 0x0000 */ unsigned long IdleRequestCanceled : 1; /* bit position: 7 */
      /* 0x0000 */ unsigned long ForceIdleTransition : 1; /* bit position: 8 */
      /* 0x0000 */ unsigned long Stopped : 1; /* bit position: 9 */
    }; /* bitfield */
    /* 0x0000 */ unsigned long Value;
  }; /* size: 0x0004 */
} NDIS_SS_IDLE_FLAGS, *PNDIS_SS_IDLE_FLAGS; /* size: 0x0004 */

typedef struct _NDIS_SS_STOP_FLAGS
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long QueryRemove : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long DeviceRemove : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned long SurpriseRemove : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned long QueryStop : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned long DeviceStop : 1; /* bit position: 4 */
      /* 0x0000 */ unsigned long SystemPower : 1; /* bit position: 5 */
      /* 0x0000 */ unsigned long NicQuiet : 1; /* bit position: 6 */
      /* 0x0000 */ unsigned long PnPOp : 1; /* bit position: 7 */
      /* 0x0000 */ unsigned long NotStarted : 1; /* bit position: 8 */
    }; /* bitfield */
    /* 0x0000 */ unsigned long Value;
  }; /* size: 0x0004 */
} NDIS_SS_STOP_FLAGS, *PNDIS_SS_STOP_FLAGS; /* size: 0x0004 */

typedef struct _NDIS_SS_CONTROL_OPS
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long Oid : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long Pause : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned long Restart : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned long Reset : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned long CheckForHang : 1; /* bit position: 4 */
    }; /* bitfield */
    /* 0x0000 */ unsigned long Value;
  }; /* size: 0x0004 */
} NDIS_SS_CONTROL_OPS, *PNDIS_SS_CONTROL_OPS; /* size: 0x0004 */

typedef struct _NBL_QUEUE
{
  /* 0x0000 */ struct _NET_BUFFER_LIST* First;
  /* 0x0004 */ struct _NET_BUFFER_LIST** Last;
} NBL_QUEUE, *PNBL_QUEUE; /* size: 0x0008 */

typedef enum _NDIS_SS_STOP_REASON
{
  NdisSSReasonUnspecified = 0,
  NdisSSQueryRemove = 1,
  NdisSSDeviceRemove = 2,
  NdisSSDeviceSurpriseRemove = 3,
  NdisSSQueryStop = 4,
  NdisSSDeviceStop = 5,
  NdisSSSystemPower = 6,
  NdisSSNicQuiet = 7,
  NdisSSPnPOp = 8,
  NdisSSNotStarted = 9,
  NdisSSStopReasonMax = 15,
} NDIS_SS_STOP_REASON, *PNDIS_SS_STOP_REASON;

typedef enum _NDIS_SS_BUSY_REASON
{
  NdisBusyOid = 33,
  NdisBusyPause = 34,
  NdisBusyRestart = 35,
  NdisBusyReset = 36,
  NdisBusyDevicePnPEvent = 37,
  NdisBusyCheckForHang = 49,
  NdisBusyDirectOid = 50,
  NdisBusyCancelDirectOid = 51,
  NdisBusySend = 52,
  NdisBusyCancelSend = 53,
  NdisBusyReceiveReturn = 54,
  NdisBusyWaitWake = 65,
} NDIS_SS_BUSY_REASON, *PNDIS_SS_BUSY_REASON;

typedef union _NDIS_SS_RESUME_REASON
{
  union
  {
    /* 0x0000 */ enum _NDIS_SS_STOP_REASON StopReason;
    /* 0x0000 */ enum _NDIS_SS_BUSY_REASON BusyReason;
    /* 0x0000 */ unsigned long Value;
  }; /* size: 0x0004 */
} NDIS_SS_RESUME_REASON, *PNDIS_SS_RESUME_REASON; /* size: 0x0004 */

typedef union _LARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    }; /* size: 0x0008 */
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ __int64 QuadPart;
  }; /* size: 0x0008 */
} LARGE_INTEGER, *PLARGE_INTEGER; /* size: 0x0008 */

typedef enum _NDIS_DEVICE_POWER_STATE
{
  NdisDeviceStateUnspecified = 0,
  NdisDeviceStateD0 = 1,
  NdisDeviceStateD1 = 2,
  NdisDeviceStateD2 = 3,
  NdisDeviceStateD3 = 4,
  NdisDeviceStateMaximum = 5,
} NDIS_DEVICE_POWER_STATE, *PNDIS_DEVICE_POWER_STATE;

typedef struct _NDIS_SELECTIVE_SUSPEND
{
  /* 0x0000 */ unsigned long Lock;
  /* 0x0004 */ unsigned long IdleTimeout;
  /* 0x0008 */ struct _NDIS_TIMER IdleTimer;
  /* 0x0050 */ unsigned long IdleTickCount;
  /* 0x0054 */ struct _KEVENT IdleWorkItemCompleteEvent;
  /* 0x0064 */ struct _KEVENT PowerSuspendCompleteEvent;
  /* 0x0074 */ struct _KEVENT IdleNotificationCompleteEvent;
  /* 0x0084 */ struct _KEVENT IdleNotificationDoneEvent;
  /* 0x0094 */ struct _KEVENT DevicePowerReadyEvent;
  /* 0x00a4 */ struct _NDIS_WORK_ITEM IdleTimerWorkItem;
  /* 0x00cc */ struct _NDIS_WORK_ITEM IdleCancelWorkItem;
  /* 0x00f4 */ struct _NDIS_IRP_WORK_ITEM ResumeWorkItem;
  /* 0x010c */ struct _NDIS_SS_IDLE_FLAGS Flags;
  /* 0x0110 */ struct _NDIS_SS_STOP_FLAGS StopFlags;
  /* 0x0114 */ struct _NDIS_SS_CONTROL_OPS PendingControlOps;
  /* 0x0118 */ long PendingPnPEventCount;
  /* 0x011c */ long PendingSendNblCount;
  /* 0x0120 */ long PendingCancelSendCount;
  /* 0x0124 */ long PendingDirectOidCount;
  /* 0x0128 */ long PendingCancelDirectOidCount;
  /* 0x012c */ long PendingPnPOpCount;
  /* 0x0130 */ struct _NBL_QUEUE PendingSendNblQueue;
  /* 0x0138 */ struct _NBL_QUEUE PendingReceiveNblQueue;
  /* 0x0140 */ long PendingReceiveReturnCount;
  /* 0x0144 */ struct _LIST_ENTRY PendingDirectOidQueue;
  /* 0x014c */ struct _NDIS_OID_CACHE_ENTRY* OidCacheArray;
  /* 0x0150 */ struct NDIS_NBL_TRACKER_HANDLE__* QueuedSendNblTracker;
  /* 0x0154 */ struct NDIS_NBL_TRACKER_HANDLE__* QueuedReceiveReturnNblTracker;
  /* 0x0158 */ unsigned short LastUnexpectedFailureLine[2];
  /* 0x015c */ union _NDIS_SS_RESUME_REASON LastResumeReason;
  /* 0x0160 */ unsigned long LastResumeContext;
  /* 0x0164 */ union _NDIS_SS_RESUME_REASON LastBusyEvent;
  /* 0x0168 */ unsigned long LastBusyContext;
  /* 0x016c */ unsigned long SuspendCount;
  /* 0x0170 */ union _LARGE_INTEGER LastSuspendTime;
  /* 0x0178 */ union _LARGE_INTEGER LastCancelTime;
  /* 0x0180 */ unsigned __int64 LastResumeLatencyMs;
  /* 0x0188 */ unsigned __int64 TotalResumeLatencyMs;
  /* 0x0190 */ unsigned __int64 LastSuspendIntervalMs;
  /* 0x0198 */ unsigned __int64 TotalSuspendedTimeMs;
  /* 0x01a0 */ enum _NDIS_DEVICE_POWER_STATE LastRequestedIdlePowerState;
  /* 0x01a4 */ long __PADDING__[1];
} NDIS_SELECTIVE_SUSPEND, *PNDIS_SELECTIVE_SUSPEND; /* size: 0x01a8 */

