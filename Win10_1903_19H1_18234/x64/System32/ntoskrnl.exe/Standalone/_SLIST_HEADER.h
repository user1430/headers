typedef union _SLIST_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned __int64 Alignment;
      /* 0x0008 */ unsigned __int64 Region;
    }; /* size: 0x0010 */
    struct // _TAG_UNNAMED_89
    {
      struct /* bitfield */
      {
        /* 0x0000 */ unsigned __int64 Depth : 16; /* bit position: 0 */
        /* 0x0000 */ unsigned __int64 Sequence : 48; /* bit position: 16 */
      }; /* bitfield */
      struct /* bitfield */
      {
        /* 0x0008 */ unsigned __int64 Reserved : 4; /* bit position: 0 */
        /* 0x0008 */ unsigned __int64 NextEntry : 60; /* bit position: 4 */
      }; /* bitfield */
    } /* size: 0x0010 */ HeaderX64;
  }; /* size: 0x0010 */
} SLIST_HEADER, *PSLIST_HEADER; /* size: 0x0010 */

