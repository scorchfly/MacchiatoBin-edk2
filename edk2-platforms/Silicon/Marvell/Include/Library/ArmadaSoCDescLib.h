/**
*
*  Copyright (C) 2018, Marvell International Ltd. and its affiliates
*
*  This program and the accompanying materials are licensed and made available
*  under the terms and conditions of the BSD License which accompanies this
*  distribution. The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/
#ifndef __ARMADA_SOC_DESC_LIB_H__
#define __ARMADA_SOC_DESC_LIB_H__

#include <Library/MvComPhyLib.h>
#include <Library/NonDiscoverableDeviceRegistrationLib.h>

//
// ComPhy SoC description
//
typedef struct {
  UINTN ComPhyId;
  UINTN ComPhyBaseAddress;
  UINTN ComPhyHpipe3BaseAddress;
  UINTN ComPhyLaneCount;
  UINTN ComPhyMuxBitCount;
  MV_COMPHY_CHIP_TYPE ComPhyChipType;
} MV_SOC_COMPHY_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescApBaseGet (
  IN OUT UINT64  *ApBase,
  IN UINT8        ApNr
  );

EFI_STATUS
EFIAPI
ArmadaSoCDescComPhyGet (
  IN OUT MV_SOC_COMPHY_DESC  **ComPhyDesc,
  IN OUT UINT8                *DescCount
  );

UINTN
EFIAPI
ArmadaSoCDescCpBaseGet (
  IN UINTN        CpIndex
  );

//
// Fuse devices SoC description
//
typedef struct {
  UINT8 BankId;
  UINT8 BankType;
  UINT8 BankOPMode;
  UINTN BankRegBase;
  UINTN OTPMemBase;
  UINTN RowCount;
  UINTN RowLength;
  UINTN RowStep;
  CHAR16  BankName[10];
  UINT8 PriBitOffset;
} MV_SOC_FUSE_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescFuseGet (
  IN OUT MV_SOC_FUSE_DESC  **FuseDesc,
  IN OUT UINTN              *DescCount
  );

//
// GPIO devices description template definition
//
#define MVHW_MAX_GPIO_DEVS       20
typedef struct {
  UINT8 GpioDevCount;
  UINTN GpioBaseAddresses[MVHW_MAX_GPIO_DEVS];
  UINTN GpioPinCount[MVHW_MAX_GPIO_DEVS];
} MVHW_GPIO_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescGpioGet (
  IN OUT MVHW_GPIO_DESC **GpioDesc
  );

//
// I2C
//
typedef struct {
  UINT8 I2cId;
  UINTN I2cBaseAddress;
} MV_SOC_I2C_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescI2cGet (
  IN OUT MV_SOC_I2C_DESC  **I2cDesc,
  IN OUT UINT8             *DescCount
  );

//
// ICU (Interrupt Consolidation Unit)
//
typedef enum {
  ICU_GROUP_NSR  = 0,
  ICU_GROUP_SR   = 1,
  ICU_GROUP_LPI  = 2,
  ICU_GROUP_VLPI = 3,
  ICU_GROUP_SEI  = 4,
  ICU_GROUP_REI  = 5,
  ICU_GROUP_MAX,
} ICU_GROUP;

typedef struct {
  ICU_GROUP Group;
  UINTN     SetSpiAddr;
  UINTN     ClrSpiAddr;
} ICU_MSI;

typedef struct {
  UINTN    IcuSpiBase;
  ICU_MSI  IcuMsi[ICU_GROUP_MAX];
} MV_SOC_ICU_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescIcuGet (
  IN OUT MV_SOC_ICU_DESC  **IcuDesc
  );

//
// MDIO
//
typedef struct {
  UINT8 MdioId;
  UINTN MdioBaseAddress;
} MV_SOC_MDIO_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescMdioGet (
  IN OUT MV_SOC_MDIO_DESC  **MdioDesc,
  IN OUT UINT8              *DescCount
  );

//
// NonDiscoverable devices SoC description
//
// AHCI
typedef struct {
  UINT8 AhciId;
  UINTN AhciBaseAddress;
  UINTN AhciMemSize;
  NON_DISCOVERABLE_DEVICE_DMA_TYPE AhciDmaType;
} MV_SOC_AHCI_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescAhciGet (
  IN OUT MV_SOC_AHCI_DESC  **AhciDesc,
  IN OUT UINT8              *DescCount
  );

// SDMMC
typedef struct {
  UINTN SdMmcBaseAddress;
  UINTN SdMmcMemSize;
  NON_DISCOVERABLE_DEVICE_DMA_TYPE SdMmcDmaType;
} MV_SOC_SDMMC_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescSdMmcGet (
  IN OUT MV_SOC_SDMMC_DESC  **SdMmcDesc,
  IN OUT UINT8               *DescCount
  );

// XHCI
typedef struct {
  UINTN XhciBaseAddress;
  UINTN XhciMemSize;
  NON_DISCOVERABLE_DEVICE_DMA_TYPE XhciDmaType;
} MV_SOC_XHCI_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescXhciGet (
  IN OUT MV_SOC_XHCI_DESC  **XhciDesc,
  IN OUT UINT8              *DescCount
  );

//
// PP2 NIC devices SoC description
//
typedef struct {
  UINTN Pp2BaseAddress;
  UINTN Pp2ClockFrequency;
} MV_SOC_PP2_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescPp2Get (
  IN OUT MV_SOC_PP2_DESC  **Pp2Desc,
  IN OUT UINT8             *DescCount
  );

//
// UTMI PHY devices SoC description
//
typedef struct {
  UINT8 UtmiPhyId;
  UINTN UtmiBaseAddress;
  UINTN UtmiConfigAddress;
  UINTN UsbConfigAddress;
} MV_SOC_UTMI_DESC;

EFI_STATUS
EFIAPI
ArmadaSoCDescUtmiGet (
  IN OUT MV_SOC_UTMI_DESC  **UtmiDesc,
  IN OUT UINT8              *DescCount
  );

//
// PCIe devices SoC description
//
EFI_STATUS
EFIAPI
ArmadaSoCDescPcieGet (
  IN OUT UINT8              *DevCount,
  IN OUT UINTN             **PcieRegBase
  );

#endif /* __ARMADA_SOC_DESC_LIB_H__ */
