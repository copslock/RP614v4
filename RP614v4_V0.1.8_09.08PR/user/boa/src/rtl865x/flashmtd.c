/*
* ----------------------------------------------------------------
* Copyright c                  Realtek Semiconductor Corporation, 2002  
* All rights reserved.
* 
* $Header: /home/cvsroot/uClinux-dist/user/boa/src/rtl865x/flashmtd.c,v 1.4 2005/12/05 09:27:51 alva_zhang Exp $
*
* Abstract: Flash driver (based on MTD) source code .
*
* $Author: alva_zhang $
*
* $Log: flashmtd.c,v $
* Revision 1.4  2005/12/05 09:27:51  alva_zhang
* *: during boa initializing,it used flash detail info ,but mtd_dev is do not initialized;so we have to specify a static value for those
*
* Revision 1.3  2005/12/02 01:16:03  alva_zhang
* *: refine the functions refer to flash base information
*
* Revision 1.2  2005/11/30 07:59:38  alva_zhang
* *: refine the defination of those functions evolved from flashdrv.c
*
* Revision 1.1  2005/11/24 10:05:48  alva_zhang
* +: evolved from flashdrv.c,and do work based on MTD;this is just an alpha version
*
*
*
*
*---------------------------------------------------------------
*/


#include <linux/config.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <linux/fcntl.h>
#include <linux/ioctl.h>

#include <linux/mtd/mtd.h>

#include "flashdrv.h"

#define SEEK_SET 0

 
// global variable mtd_dev;
MTD_FlashDev mtd_dev={

};

/*
 *  bdinfo instance in SDRAM.
 */
bdinfo_t	bdinfo;

void flashdrv_init(void)
{
  //  unsigned short i;
  //struct mtd_info *mymtd;
 // struct map_info *mymap;
 
  //FILE* fp;
  memset(&mtd_dev, 0, sizeof(MTD_FlashDev));

  mtd_dev.bdinfobase = FLASH_MAP_BOARD_INFO_ADDR;
  mtd_dev.bdinfosize = FLASH_MAP_BOARD_INFO_SIZE;

  mtd_dev.ccfgbase = FLASH_MAP_CCFG_IMAGE_ADDR;
  mtd_dev.ccfgsize = FLASH_MAP_CCFG_IMAGE_SIZE;

  mtd_dev.kernbase = FLASH_MAP_RUN_IMAGE_ADDR;
  mtd_dev.kernsize = FLASH_MAP_RUN_IMAGE_SIZE;

  mtd_dev.rootfsbase = FLASH_MAP_RUN_IMAGE_ADDR+FLASH_MAP_RUN_IMAGE_SIZE;

  //if((fp = open( "/dev/mtd0", O_RDWR)) !=-1) 	
  if((mtd_dev.p[0].fd = open( "/dev/mtd0", O_RDWR)) !=-1) 
    {
       mtd_dev.partcnt = mtd_dev.partcnt + 1;  
	
      ioctl(mtd_dev.p[0].fd, MEMINFOINIT, &mtd_dev);
      
      mtd_dev.p[0].base = CONFIG_RTL865X_CUSTOM_LOADER_SEG1_ADDRESS;
      mtd_dev.p[0].size = CONFIG_RTL865X_CUSTOM_LOADER_SEG1_SIZE;      
   
      mtd_dev.chipbase = FLASH_BASE;
   
      if((mtd_dev.p[1].fd = open( "/dev/mtd1", O_RDWR)) !=-1) 
        {
          mtd_dev.partcnt = mtd_dev.partcnt+1;          
          //mymtd=(struct mtd_info *)(mtd_dev.p[1].fd)->private_data;
          mtd_dev.p[1].base = CONFIG_RTL865X_CUSTOM_LOADER_SEG2_ADDRESS;
          mtd_dev.p[1].size = CONFIG_RTL865X_CUSTOM_LOADER_SEG2_SIZE;      
         // mtd_dev.p[1].flag = mymtd->flags; 

          
          if((mtd_dev.p[2].fd = open( "/dev/mtd2", O_RDWR)) !=-1) 
            {
              mtd_dev.partcnt = mtd_dev.partcnt+1;              
              //mymtd=(struct mtd_info *)((void*)(mtd_dev.p[2].fd))->private_data;
              mtd_dev.p[2].base = CONFIG_RTL865X_CUSTOM_LOADER_SEG3_ADDRESS;
              mtd_dev.p[2].size = CONFIG_RTL865X_CUSTOM_LOADER_SEG3_SIZE;      
              //mtd_dev.p[2].flag = mymtd->flags; 
              
              
              if((mtd_dev.p[3].fd = open( "/dev/mtd3", O_RDWR)) !=-1) 
                {
                  mtd_dev.partcnt = mtd_dev.partcnt+1;                  
                 //mymtd=(struct mtd_info *)((void*)(mtd_dev.p[3].fd))->private_data;
                  mtd_dev.p[3].base = mtd_dev.kernbase;
                  mtd_dev.p[3].size = mtd_dev.kernsize;
                  //mtd_dev.p[3].flag = mymtd->flags; 

                  
                  if((mtd_dev.p[4].fd = open( "/dev/mtd4", O_RDWR)) !=-1) 
                    {
                      mtd_dev.partcnt = mtd_dev.partcnt+1;
                      //mymtd=(struct mtd_info *)((void*)(mtd_dev.p[4].fd))->private_data;
                      mtd_dev.p[4].base = mtd_dev.rootfsbase;
			 mtd_dev.rootfssize = mtd_dev.chipsize-CONFIG_FLASH_SIZE_OF_KERNEL;
                      mtd_dev.p[4].size = mtd_dev.rootfssize;
                     // mtd_dev.p[4].flag = mymtd->flags; 


                      if((mtd_dev.p[5].fd = open( "/dev/mtd5", O_RDWR))==-1) 
                        {
                          mtd_dev.partcnt = mtd_dev.partcnt+1;
                         // mymtd=(struct mtd_info *)((void*)(mtd_dev.p[5].fd))->private_data;
                          mtd_dev.p[5].base = mtd_dev.bdinfobase;
                          mtd_dev.p[5].size = mtd_dev.bdinfosize+mtd_dev.ccfgsize;
                        //  mtd_dev.p[5].flag = mymtd->flags; 
                        }//end of  if((mtd_dev.p[5].fd = open( "/dev/mtd5", O_RDWR))==-1) 
                    }//end of  if((mtd_dev.p[4].fd = open( "/dev/mtd4", O_RDWR))==-1) 
                }//end of if((mtd_dev.p[3].fd = open( "/dev/mtd3", O_RDWR))==-1) 
            }//end of  if((mtd_dev.p[2].fd = open( "/dev/mtd2", O_RDWR))==-1) 
        }//end of  if((mtd_dev.p[1].fd = open( "/dev/mtd1", O_RDWR))==-1) 
    } //end of if((mtd_dev.p[0].fd = open( "/dev/mtd0", O_RDWR))==-1) 
  

#ifdef _SUPPORT_LARGE_FLASH_
    /* read bdinfo before any read to flash (to recover flash JUMP code) */
    flashdrv_read( &bdinfo, (void*)(FLASH_MAP_BOARD_INFO_ADDR), sizeof(bdinfo_t) );
/*
    rtlglue_printf( "\n*** read bdinfo ***\n0x%08x\n0x%08x\n\n", bdinfo.BackupInst[0], bdinfo.BackupInst[1] );
*/
#endif

}



#ifdef _SUPPORT_LARGE_FLASH_
/*
 *  flashdrv_isOver5xBBootInstructions(), flashdrv_recoverBootInstructions(),
 *  flashdrv_isInjected() and flashdrv_backupAndModifyBootCode() are used for 865xB's bug.
 *
 *  Before read/write flash memory, program should call flashdrv_isOver5xBBootInstructions() to ensure that
 *    the [startOffset,endOffset) range is not overlapped with the boot J instruction.
 *    The returned pInstructionOffset is used to pass to flashdrv_backupAndModifyBootCode().
 */
int32 flashdrv_isOver5xBBootInstructions( uint32 startOffset, uint32 endOffset, uint32 *pInstructionOffset )
{
    *pInstructionOffset = 0;

    /* Only 865XB's revB needs to check. */
    if ( !IS_865XB() )
    {
        /* Not 865xB, it is ok. */
        return FALSE;
    }
    else if ( ( REG32( CRMR_ADDR ) & 0x000f0000 ) != 0x00010000 )
    {
        /* 865XB, but not revB, it is ok. */
        return FALSE;
    }

    if ( mtd_dev.chipsize == 0x0800000 ) /* 8MB flash */
    {
        *pInstructionOffset = 0x0400000;
        if ( startOffset < 0x0400008 && endOffset > 0x0400000 )
        {
            return TRUE;
        }
    }
    else if ( mtd_dev.chipsize == 0x1000000 ) /* 16MB flash */
    {
        *pInstructionOffset = 0x0C00000;
        if ( startOffset < 0x0C00008 &&  endOffset > 0x0C00000 )
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*
 *  flashdrv_recoverBootInstructions() is used to recover code that overwriten by JUMP instructions.
 *  Typically, this function is called by flashdrv_read().
 *
 *  Warning: User must read bdinfo structure from flash before calling this function.
 */
int32 flashdrv_recoverBootInstructions( uint32* pStartAddrToRecover )
{
  pStartAddrToRecover[0] = bdinfo.BackupInst[0];
  pStartAddrToRecover[1] = bdinfo.BackupInst[1];
#ifdef _DEBUG_
  rtlglue_printf("\n*** Recover Instruction Mechanism Fired ***\nbdinfo.BackupInst[0]=0x%08x\nbdinfo.BackupInst[1]=0x%08x\n\n",
                 bdinfo.BackupInst[0] ,bdinfo.BackupInst[1] );
#endif//_DEBUG_
  return SUCCESS;
}
#endif //_SUPPORT_LARGE_FLASH_

uint32 
flashdrv_read(void *dstAddr_P, void *srcAddr_P, uint32 size)
{
#ifdef _SUPPORT_LARGE_FLASH_
  uint32 startOffset; /* start offset to read */
  uint32 endOffset;   /* end offset to read */
  uint32 InstructionOffset; /* offset of boot instruction */
#endif/*_SUPPORT_LARGE_FLASH_*/

  ASSERT_CSP( srcAddr_P );
  ASSERT_CSP( dstAddr_P );
  
  memcpy(dstAddr_P, srcAddr_P, size);
  
#ifdef _SUPPORT_LARGE_FLASH_
  startOffset = ((uint32)srcAddr_P) - FLASH_BASE;
  endOffset = startOffset + size;
  if ( TRUE == flashdrv_isOver5xBBootInstructions( startOffset, endOffset, &InstructionOffset ) )
    {
      uint32* pStartAddrToRecover;
      
      pStartAddrToRecover = (uint32*)( ((uint32)dstAddr_P+(InstructionOffset-startOffset)) );
      flashdrv_recoverBootInstructions( pStartAddrToRecover );
    }
#endif/*_SUPPORT_LARGE_FLASH_*/
    
  return 0;
}

/*
static struct mtd_partition rtl865x_parts[] = {
    { name: "boot1", offset: CONFIG_RTL865X_CUSTOM_LOADER_SEG1_ADDRESS, size: CONFIG_RTL865X_CUSTOM_LOADER_SEG1_SIZE, mask_flags: MTD_WRITEABLE },
    { name: "boot2", offset: CONFIG_RTL865X_CUSTOM_LOADER_SEG2_ADDRESS, size: CONFIG_RTL865X_CUSTOM_LOADER_SEG2_SIZE, mask_flags: MTD_WRITEABLE },
    { name: "boot3", offset: CONFIG_RTL865X_CUSTOM_LOADER_SEG3_ADDRESS, size: CONFIG_RTL865X_CUSTOM_LOADER_SEG3_SIZE, mask_flags: MTD_WRITEABLE },
    { name: "kernel", offset: CONFIG_RTL865X_CUSTOM_RUNTIME_ADDRESS, size: CONFIG_FLASH_SIZE_OF_KERNEL, mask_flags:MTD_WRITEABLE },
    { name: "rootfs", offset: CONFIG_RTL865X_CUSTOM_RUNTIME_ADDRESS+CONFIG_FLASH_SIZE_OF_KERNEL, size: WINDOW_SIZE-CONFIG_FLASH_SIZE_OF_KERNEL, mask_flags:MTD_WRITEABLE },
       { name: "bdinfo", offset: CONFIG_RTL865X_CUSTOM_LOADER_SEG1_ADDRESS+CONFIG_RTL865X_CUSTOM_LOADER_SEG1_SIZE, size: CONFIG_RTL865X_CUSTOM_LOADER_SEG2_ADDRESS- CONFIG_RTL865X_CUSTOM_LOADER_SEG1_ADDRESS,mask_flags: MTD_WRITEABLE },
};
*/
/* Here we only consider write  partition 5,4,3,because we do NOT write bootloader  in uclinux environment */
uint32 flashdrv_write(void *dstAddr_P, void *srcAddr_P, uint32 size)
{
  unsigned int poffset;
  // Here partition5 bdinfo&ccfg is mostly common writen !
  if(((unsigned int)dstAddr_P>=mtd_dev.p[5].base)&&(((unsigned int)dstAddr_P+size)<=(mtd_dev.p[5].base+mtd_dev.p[5].size)))
    {
      poffset=(unsigned int)dstAddr_P -mtd_dev.p[5].base;
      lseek(mtd_dev.p[5].fd,poffset,SEEK_SET);
      write(mtd_dev.p[5].fd,srcAddr_P,size);                
    }
  else if(((unsigned int)dstAddr_P>=mtd_dev.p[4].base)&&(((unsigned int)dstAddr_P+size)<=(mtd_dev.p[4].base+mtd_dev.p[4].size)))
    {
      poffset=(unsigned int)dstAddr_P -mtd_dev.p[4].base;
      lseek(mtd_dev.p[4].fd,poffset,SEEK_SET);
      write(mtd_dev.p[4].fd,srcAddr_P,size);                
    }
  else if(((unsigned int)dstAddr_P>=mtd_dev.p[3].base)&&(((unsigned int)dstAddr_P+size)<=(mtd_dev.p[3].base+mtd_dev.p[3].size)))
    {
      poffset=(unsigned int)dstAddr_P -mtd_dev.p[3].base;
      lseek(mtd_dev.p[3].fd,poffset,SEEK_SET);
      write(mtd_dev.p[3].fd,srcAddr_P,size);                
    }
  else if(((unsigned int)dstAddr_P>=mtd_dev.p[2].base)&&(((unsigned int)dstAddr_P+size)<=(mtd_dev.p[2].base+mtd_dev.p[2].size)))
    {
      poffset=(unsigned int)dstAddr_P -mtd_dev.p[2].base;
      lseek(mtd_dev.p[2].fd,poffset,SEEK_SET);
      write(mtd_dev.p[2].fd,srcAddr_P,size);                
    }
  // here we do consider that loader is writen into boot1-3 partition and not beyond boot3 
  else if(((unsigned int)dstAddr_P>=mtd_dev.p[0].base)&&((unsigned int)dstAddr_P<=(mtd_dev.p[0].base+mtd_dev.p[0].size)))
  {
    poffset=(unsigned int)dstAddr_P -mtd_dev.p[0].base;
    lseek(mtd_dev.p[0].fd,poffset,SEEK_SET);
    write(mtd_dev.p[0].fd,srcAddr_P,size);
    if(size>mtd_dev.p[0].size-poffset)
      { 
        size=size -(mtd_dev.p[0].size-poffset);
        lseek(mtd_dev.p[1].fd,0,SEEK_SET);
        write(mtd_dev.p[1].fd,(srcAddr_P+mtd_dev.p[0].size-poffset),size);
        if(size>mtd_dev.p[1].size)
          { 
            size=size-mtd_dev.p[1].size;
            lseek(mtd_dev.p[2].fd,0,SEEK_SET);
            write(mtd_dev.p[2].fd,(srcAddr_P+mtd_dev.p[0].size-poffset+mtd_dev.p[1].size),size);     
          }
      }
  }
  else { printf("Error,dest location or size is not correct, please check it!\n"); return 1;}
  return 0;
         
}

//Write check is done by flashdrv_write, so wo do NOT need  function flashdrv_isLoaderOverwritten ;
int8 flashdrv_isLoaderOverwritten( uint8* dst, uint32 len )
{
    return FALSE;
}

/*
 *  flashdrv_backupAndModifyBootCode() is used to inject JUMP instructions.
 *  Before injection, it will backup original instructions in BDINFO (by calling flashdrv_updateImg()).
 *  pStartAddrToBackup is pointed to the address used to inject JUMP instructions.
 *  Typically, this function is called by flashdrv_updateImg().
 *
 *  Warning: User must read bdinfo structure from flash before calling this function.
 */
int32 flashdrv_backupAndModifyBootInstructions( uint32* pStartAddrToBackup )
{
    // will overwrite the 4/8MB'th byte, backup them.

    bdinfo.BackupInst[0] =  pStartAddrToBackup[0];
    bdinfo.BackupInst[1] =  pStartAddrToBackup[1];
    if( flashdrv_updateImg((void *)&bdinfo, (void*)mtd_dev.bdinfobase, sizeof(bdinfo_t) ) )
    {
        rtlglue_printf("\nupdate bdinfo FAIL when backuping instructions!\n\n");
        return 1;
    }    

    /* modify the source code */
    pStartAddrToBackup[0] = 0x0B800080; /* j  0xbe000200 */
    pStartAddrToBackup[1] = 0x00000000; /* nop           */
    
#ifdef _DEBUG_
    rtlglue_printf("\n*** Backup Instruction Mechanism Fired ***\nbdinfo.BackupInst[0]=0x%08x\nbdinfo.BackupInst[1]=0x%08x\n\n",
           bdinfo.BackupInst[0] ,bdinfo.BackupInst[1] );
#endif//_DEBUG_
    return SUCCESS;
}


/*
 *  flashdrv_isInjected() is used to check if JUMP instructions are injected.
 *  pStartAddrToCheck is pointed to the address to be check.
 *  Typically, this function is called by fileSys_updateBootImage().
 */
int32 flashdrv_isInjected( uint32* pStartAddrToCheck )
{
    if ( pStartAddrToCheck[0] == 0x0B800080 && /* j  0xbe000200 */
         pStartAddrToCheck[1] == 0x00000000 )  /* nop           */
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
unsigned int flashdrv_updateImg(void * srcAddr_P, void * dstAddr_P, uint32 size)
{
  unsigned int retval=-1;
#ifdef _SUPPORT_LARGE_FLASH_
  if ( mtd_dev.chipsize > 0x400000 )
    {
      /* If the first chip is larger than 4MB (not including 4MB),
       * 865xB has bug to boot system.
       * We must backup instructions at 4MB or 8MB position into bdinfo, and recover them in flashdrv_read().
       */
      uint32 startOffset; /* start offset to write */
      uint32 endOffset;   /* end offset to write */
      uint32 InstructionOffset; /* offset of boot instruction */
      
      startOffset = ((uint32)dstAddr_P) - mtd_dev.chipbase;
      endOffset = startOffset + size;
      
      /* 865xB has bug when booting from a single 8MB or 16MB flash. */
      if ( TRUE == flashdrv_isOver5xBBootInstructions( startOffset, endOffset, &InstructionOffset ) )
        {
          uint32 *pStartAddrToBackup;
          void *pAddrToInject;
          
          pStartAddrToBackup = (uint32*)( ((uint32)srcAddr_P+(InstructionOffset-startOffset)) );
          rtlglue_printf("before backup ...\n%p=0x%08x\n%p=0x%08x\n",&pStartAddrToBackup[0],pStartAddrToBackup[0],&pStartAddrToBackup[1],pStartAddrToBackup[1]);
          flashdrv_backupAndModifyBootInstructions( pStartAddrToBackup );

          /* Inject right now! To reduce risk .... */
          pAddrToInject = (void*)( (uint32)((uint32)dstAddr_P+(InstructionOffset-startOffset)) );
          rtlglue_printf("flashdrv_write(dst=%p,src=%p,size=0x%08x)\n",pAddrToInject, pStartAddrToBackup, sizeof(bdinfo.BackupInst));
          flashdrv_write(pAddrToInject, pStartAddrToBackup, sizeof(bdinfo.BackupInst) );
        }
    }
#endif/*_SUPPORT_LARGE_FLASH_*/
  
  retval = flashdrv_write(dstAddr_P, srcAddr_P, size);
  return retval;
}

unsigned int flashdrv_filewrite(FILE *fp,int size,void *dstP)
{
  int i;
  int nWritten; /* completed bytes */
  volatile unsigned char data[4096];
  volatile uint16 *dstAddr;

  nWritten = 0;
  dstAddr = dstP;

  while ( nWritten < size )
    {
      int nRead;
      
      /* fill buffer with file */
      for( i = 0, nRead = 0; i < sizeof(data) && ( i < (size-nWritten) ); i++, nRead++ )
        {
          data[i] = fgetc(fp);
        }

      if ( 0 != flashdrv_updateImg( (void*)data, (void*)dstAddr, nRead ) )
        return 1;
      
      dstAddr += nRead >> 1;
      nWritten += nRead;
    }
  return 0;

}

/*
uint32 flashdrv_getBlockBase( uint32 ChipSeq )
{
    return mtd_dev.chipbase; 
}

 * 
 * Offset is related to flashbase, such as: 0x00004567.
 * blockOffset is returned with related to flashbase, for example: 0x00004000.
 *
int32 flashdrv_getBlockSizeAndBlockOffset( uint32 Offset, uint32 ChipSeq, uint32 *blockNum, uint32* blockOffset, uint32 *blockSize )
{
  uint32 BlockSeq;
  
  assert( flash_chip_info[ChipSeq].BlockOffset != NULL );
  
  for( BlockSeq = 0; BlockSeq < flash_chip_info[ChipSeq].NumOfBlock; BlockSeq++ )
    {
      //rtlglue_printf("[%d][%d]: 0x%08x\n", ChipSeq, BlockSeq, blockbase + (uint32)flash_chip_info[ChipSeq].BlockOffset[ BlockSeq + 1 ] );
      if ( (uint32)flash_chip_info[ChipSeq].BlockOffset[ BlockSeq + 1 ] > Offset )
        {
          goto found;
        }
    }
  // Not found 
  return 1;

 found:
  if ( blockNum ) *blockNum = BlockSeq;
  if ( blockOffset ) *blockOffset = flash_chip_info[ChipSeq].BlockOffset[BlockSeq];
  if ( blockSize ) *blockSize = flash_chip_info[ChipSeq].BlockOffset[BlockSeq+1] - flash_chip_info[ChipSeq].BlockOffset[BlockSeq];
 return 0;
}
*/


/*
 *  The following functions are used to return the addresses of BDINFO, CCFG, RUNTIME IMAGE.
 *
 *	These addresses are decided by the flash type and size.
 *  By calling these functions, we no more need compile flags.
 *
 */
uint32 flashdrv_getBoardInfoAddr()
{
	return  FLASH_BASE+CONFIG_RTL865X_CUSTOM_BDINFO_SIZE; 
	//return mtd_dev.bdinfobase;
}

uint32 flashdrv_getCcfgImageAddr()
{
	return  FLASH_BASE+CONFIG_RTL865X_CUSTOM_CCFG_ADDRESS; 
	//return mtd_dev.ccfgbase;
}

uint32 flashdrv_getRunImageAddr()
{
       return  FLASH_BASE+CONFIG_RTL865X_CUSTOM_RUNTIME_ADDRESS; 
	//return  mtd_dev.kernbase;
	
}

uint32 flashdrv_getFlashBase()
{
       return  FLASH_BASE ;
	//return mtd_dev.chipbase;
}


