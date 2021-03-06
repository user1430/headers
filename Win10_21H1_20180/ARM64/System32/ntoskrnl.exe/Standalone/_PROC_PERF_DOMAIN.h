typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0008 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0010 */

typedef struct _KAFFINITY_EX
{
  /* 0x0000 */ unsigned short Count;
  /* 0x0002 */ unsigned short Size;
  /* 0x0004 */ unsigned long Reserved;
  /* 0x0008 */ unsigned __int64 Bitmap[20];
} KAFFINITY_EX, *PKAFFINITY_EX; /* size: 0x00a8 */

typedef struct _PROC_PERF_QOS_CLASS_POLICY
{
  /* 0x0000 */ unsigned long MaxPolicyPercent;
  /* 0x0004 */ unsigned long MaxEquivalentFrequencyPercent;
  /* 0x0008 */ unsigned long MinPolicyPercent;
  /* 0x000c */ unsigned long AutonomousActivityWindow;
  /* 0x0010 */ unsigned long EnergyPerfPreference;
  /* 0x0014 */ unsigned char ProvideGuidance;
  /* 0x0015 */ unsigned char AllowThrottling;
  /* 0x0016 */ unsigned char PerfBoostMode;
  /* 0x0017 */ unsigned char LatencyHintPerf;
  /* 0x0018 */ unsigned char TrackDesiredCrossClass;
  /* 0x0019 */ char __PADDING__[3];
} PROC_PERF_QOS_CLASS_POLICY, *PPROC_PERF_QOS_CLASS_POLICY; /* size: 0x001c */

typedef struct _PERF_CONTROL_STATE_SELECTION
{
  /* 0x0000 */ unsigned __int64 SelectedState;
  /* 0x0008 */ unsigned long SelectedPercent;
  /* 0x000c */ unsigned long SelectedFrequency;
  /* 0x0010 */ unsigned long MinPercent;
  /* 0x0014 */ unsigned long MaxPercent;
  /* 0x0018 */ unsigned long TolerancePercent;
  /* 0x001c */ unsigned long EppPercent;
  /* 0x0020 */ unsigned long AutonomousActivityWindow;
  /* 0x0024 */ unsigned char Autonomous;
  /* 0x0025 */ unsigned char InheritFromDomain;
  /* 0x0026 */ char __PADDING__[2];
} PERF_CONTROL_STATE_SELECTION, *PPERF_CONTROL_STATE_SELECTION; /* size: 0x0028 */

typedef struct _PROC_PERF_DOMAIN
{
  /* 0x0000 */ struct _LIST_ENTRY Link;
  /* 0x0010 */ struct _PROC_PERF_CHECK_CONTEXT* Master;
  /* 0x0018 */ struct _KAFFINITY_EX Members;
  /* 0x00c0 */ unsigned __int64 DomainContext;
  /* 0x00c8 */ unsigned long ProcessorCount;
  /* 0x00cc */ unsigned char EfficiencyClass;
  /* 0x00cd */ unsigned char NominalPerformanceClass;
  /* 0x00ce */ unsigned char HighestPerformanceClass;
  /* 0x00d0 */ struct _PROC_PERF_CONSTRAINT* Processors;
  /* 0x00d8 */ void* GetFFHThrottleState /* function */;
  /* 0x00e0 */ void* TimeWindowHandler /* function */;
  /* 0x00e8 */ void* BoostPolicyHandler /* function */;
  /* 0x00f0 */ void* BoostModeHandler /* function */;
  /* 0x00f8 */ void* AutonomousActivityWindowHandler /* function */;
  /* 0x0100 */ void* AutonomousModeHandler /* function */;
  /* 0x0108 */ void* ReinitializeHandler /* function */;
  /* 0x0110 */ void* PerfSelectionHandler /* function */;
  /* 0x0118 */ void* PerfControlHandler /* function */;
  /* 0x0120 */ void* DomainPerfControlHandler /* function */;
  /* 0x0128 */ void* PerfUpdateHwDebugData /* function */;
  /* 0x0130 */ unsigned long MaxFrequency;
  /* 0x0134 */ unsigned long NominalFrequency;
  /* 0x0138 */ unsigned long MaxPercent;
  /* 0x013c */ unsigned long MinPerfPercent;
  /* 0x0140 */ unsigned long MinThrottlePercent;
  /* 0x0144 */ unsigned long AdvertizedMaximumFrequency;
  /* 0x0148 */ unsigned __int64 MinimumRelativePerformance;
  /* 0x0150 */ unsigned __int64 NominalRelativePerformance;
  /* 0x0158 */ unsigned char NominalRelativePerformancePercent;
  /* 0x0159 */ unsigned char Coordination;
  /* 0x015a */ unsigned char HardPlatformCap;
  /* 0x015b */ unsigned char AffinitizeControl;
  /* 0x015c */ unsigned char EfficientThrottle;
  /* 0x015d */ unsigned char AllowSchedulerDirectedPerfStates;
  /* 0x015e */ unsigned char InitiateAllProcessors;
  /* 0x015f */ unsigned char AllowVmPerfSelection;
  /* 0x0160 */ unsigned long VmFrequencyStepMhz;
  /* 0x0164 */ unsigned long VmHighestFrequencyMhz;
  /* 0x0168 */ unsigned long VmNominalFrequencyMhz;
  /* 0x016c */ unsigned long VmLowestFrequencyMhz;
  /* 0x0170 */ unsigned char AutonomousMode;
  /* 0x0171 */ unsigned char ProvideGuidance;
  /* 0x0174 */ unsigned long DesiredPercent;
  /* 0x0178 */ unsigned long GuaranteedPercent;
  /* 0x017c */ unsigned char EngageResponsivenessOverrides;
  /* 0x0180 */ struct _PROC_PERF_QOS_CLASS_POLICY QosPolicies[5];
  /* 0x020c */ unsigned long QosDisableReasons[5];
  /* 0x0220 */ unsigned short QosEquivalencyMasks[5];
  /* 0x022a */ unsigned char QosSupported;
  /* 0x022c */ volatile unsigned long SelectionGeneration;
  /* 0x0230 */ struct _PERF_CONTROL_STATE_SELECTION QosSelection[5];
  /* 0x02f8 */ unsigned __int64 PerfChangeTime;
  /* 0x0300 */ unsigned long PerfChangeIntervalCount;
  /* 0x0304 */ unsigned char Force;
  /* 0x0305 */ unsigned char Update;
  /* 0x0306 */ unsigned char Apply;
  /* 0x0307 */ char __PADDING__[1];
} PROC_PERF_DOMAIN, *PPROC_PERF_DOMAIN; /* size: 0x0308 */

