#pragma once

#include "descriptors.h"
#include "../mip_result.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

namespace mscl {
class MipSerializer;
namespace commands_rtk {

namespace C {
struct mip_interface;
} // namespace C

////////////////////////////////////////////////////////////////////////////////
///@addtogroup MipCommands
///@{
///@defgroup rtk_commands_cpp  RTKCommands
///
///@{

////////////////////////////////////////////////////////////////////////////////
// Descriptors
////////////////////////////////////////////////////////////////////////////////

enum 
{
    DESCRIPTOR_SET                   = 0x0F,
    
    CMD_GET_STATUS_FLAGS             = 0x01,
    CMD_GET_IMEI                     = 0x02,
    CMD_GET_IMSI                     = 0x03,
    CMD_GET_ICCID                    = 0x04,
    CMD_GET_RSSI                     = 0x05,
    CMD_CONNECTED_DEVICE_TYPE        = 0x06,
    CMD_GET_ACT_CODE                 = 0x07,
    CMD_GET_MODEM_FIRMWARE_VERSION   = 0x08,
    CMD_SERVICE_STATUS               = 0x0A,
    CMD_PROD_ERASE_STORAGE           = 0x20,
    CMD_CONTROL                      = 0x21,
    CMD_MODEM_HARD_RESET             = 0x22,
    
    REPLY_GET_STATUS_FLAGS           = 0x81,
    REPLY_GET_IMEI                   = 0x82,
    REPLY_GET_IMSI                   = 0x83,
    REPLY_GET_ICCID                  = 0x84,
    REPLY_CONNECTED_DEVICE_TYPE      = 0x86,
    REPLY_GET_ACT_CODE               = 0x87,
    REPLY_GET_MODEM_FIRMWARE_VERSION = 0x88,
    REPLY_GET_RSSI                   = 0x85,
    REPLY_SERVICE_STATUS             = 0x8A,
};

////////////////////////////////////////////////////////////////////////////////
// Shared Type Definitions
////////////////////////////////////////////////////////////////////////////////

enum class MediaSelector : uint8_t
{
    MEDIA_EXTERNALFLASH = 0,  ///<  
    MEDIA_SD            = 1,  ///<  
};

enum class LedAction : uint8_t
{
    LED_NONE    = 0,  ///<  
    LED_FLASH   = 1,  ///<  
    LED_PULSATE = 2,  ///<  
};


////////////////////////////////////////////////////////////////////////////////
// Mip Fields
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_get_status_flags  Get RTK Device Status Flags
///
///@{

struct GetStatusFlags
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_GET_STATUS_FLAGS;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    enum class StatusFlagsLegacy : uint32_t
    {
        CONTROLLERSTATE      = 0x07,
        PLATFORMSTATE        = 0xF8,
        CONTROLLERSTATUSCODE = 0x700,
        PLATFORMSTATUSCODE   = 0x3800,
        RESETCODE            = 0xC000,
        SIGNALQUALITY        = 0xF0000,
        RESERVED             = 0xFFF00000,
        RSSI                 = 0x3F00000,
        RSRP                 = 0xC000000,
        RSRQ                 = 0x30000000,
        SINR                 = 0xC0000000,
    };
    
    enum class StatusFlags : uint32_t
    {
        MODEM_STATE             = 0x0F,
        CONNECTION_TYPE         = 0xF0,
        RSSI                    = 0xFF00,
        SIGNAL_QUALITY          = 0xF0000,
        TOWER_CHANGE_INDICATOR  = 0xF00000,
        NMEA_TIMEOUT            = 0x1000000,
        SERVER_TIMEOUT          = 0x2000000,
        RTCM_TIMEOUT            = 0x4000000,
        DEVICE_OUT_OF_RANGE     = 0x8000000,
        CORRECTIONS_UNAVAILABLE = 0x10000000,
        RESERVED                = 0x20000000,
        VERSION                 = 0xC0000000,
    };
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_GET_STATUS_FLAGS;
        
        StatusFlags flags;
        
    };
};
void insert(MipSerializer& serializer, const GetStatusFlags& self);
void extract(MipSerializer& serializer, GetStatusFlags& self);

void insert(MipSerializer& serializer, const GetStatusFlags::Response& self);
void extract(MipSerializer& serializer, GetStatusFlags::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_get_imei  Get RTK Device IMEI (International Mobile Equipment Identifier)
///
///@{

struct GetImei
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_GET_IMEI;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_GET_IMEI;
        
        char IMEI[32];
        
    };
};
void insert(MipSerializer& serializer, const GetImei& self);
void extract(MipSerializer& serializer, GetImei& self);

void insert(MipSerializer& serializer, const GetImei::Response& self);
void extract(MipSerializer& serializer, GetImei::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_get_imsi  Get RTK Device IMSI (International Mobile Subscriber Identifier)
///
///@{

struct GetImsi
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_GET_IMSI;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_GET_IMSI;
        
        char IMSI[32];
        
    };
};
void insert(MipSerializer& serializer, const GetImsi& self);
void extract(MipSerializer& serializer, GetImsi& self);

void insert(MipSerializer& serializer, const GetImsi::Response& self);
void extract(MipSerializer& serializer, GetImsi::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_get_iccid  Get RTK Device ICCID (Integrated Circuit Card Identification [SIM Number])
///
///@{

struct GetIccid
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_GET_ICCID;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_GET_ICCID;
        
        char ICCID[32];
        
    };
};
void insert(MipSerializer& serializer, const GetIccid& self);
void extract(MipSerializer& serializer, GetIccid& self);

void insert(MipSerializer& serializer, const GetIccid::Response& self);
void extract(MipSerializer& serializer, GetIccid::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_connected_device_type  Configure or read the type of the connected device
///
///@{

struct ConnectedDeviceType
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_CONNECTED_DEVICE_TYPE;
    
    static const bool HAS_WRITE_FUNCTION = true;
    static const bool HAS_READ_FUNCTION = true;
    static const bool HAS_SAVE_FUNCTION = true;
    static const bool HAS_LOAD_FUNCTION = true;
    static const bool HAS_RESET_FUNCTION = true;
    
    enum class Type : uint8_t
    {
        GENERIC = 0,  ///<  
        GQ7     = 1,  ///<  
    };
    
    MipFunctionSelector function;
    Type devType;
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_CONNECTED_DEVICE_TYPE;
        
        Type devType;
        
    };
};
void insert(MipSerializer& serializer, const ConnectedDeviceType& self);
void extract(MipSerializer& serializer, ConnectedDeviceType& self);

void insert(MipSerializer& serializer, const ConnectedDeviceType::Response& self);
void extract(MipSerializer& serializer, ConnectedDeviceType::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_get_act_code  Get RTK Device Activation Code
///
///@{

struct GetActCode
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_GET_ACT_CODE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_GET_ACT_CODE;
        
        char ActivationCode[32];
        
    };
};
void insert(MipSerializer& serializer, const GetActCode& self);
void extract(MipSerializer& serializer, GetActCode& self);

void insert(MipSerializer& serializer, const GetActCode::Response& self);
void extract(MipSerializer& serializer, GetActCode::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_get_modem_firmware_version  Get RTK Device's Cell Modem Firmware version number
///
///@{

struct GetModemFirmwareVersion
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_GET_MODEM_FIRMWARE_VERSION;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_GET_MODEM_FIRMWARE_VERSION;
        
        char ModemFirmwareVersion[32];
        
    };
};
void insert(MipSerializer& serializer, const GetModemFirmwareVersion& self);
void extract(MipSerializer& serializer, GetModemFirmwareVersion& self);

void insert(MipSerializer& serializer, const GetModemFirmwareVersion::Response& self);
void extract(MipSerializer& serializer, GetModemFirmwareVersion::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_get_rssi  None
/// Get the RSSI and connected/disconnected status of modem
///
///@{

struct GetRssi
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_GET_RSSI;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_GET_RSSI;
        
        bool valid;
        int32_t rssi;
        int32_t signalQuality;
        
    };
};
void insert(MipSerializer& serializer, const GetRssi& self);
void extract(MipSerializer& serializer, GetRssi& self);

void insert(MipSerializer& serializer, const GetRssi::Response& self);
void extract(MipSerializer& serializer, GetRssi::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_service_status  None
/// The 3DMRTK will send this message to the server to indicate that the connection should remain open. The Server will respond with information and status.
///
///@{

struct ServiceStatus
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_SERVICE_STATUS;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    enum class ServiceFlags : uint8_t
    {
        THROTTLE                = 0x01,
        CORRECTIONS_UNAVAILABLE = 0x02,
        RESERVED                = 0xFC,
    };
    
    uint32_t reserved1;
    uint32_t reserved2;
    
    struct Response
    {
        static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
        static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::REPLY_SERVICE_STATUS;
        
        ServiceFlags flags;
        uint32_t recievedBytes;
        uint32_t lastBytes;
        uint64_t lastBytesTime;
        
    };
};
void insert(MipSerializer& serializer, const ServiceStatus& self);
void extract(MipSerializer& serializer, ServiceStatus& self);

void insert(MipSerializer& serializer, const ServiceStatus::Response& self);
void extract(MipSerializer& serializer, ServiceStatus::Response& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_prod_erase_storage  None
/// This command will erase the selected media to a raw and unitialized state. ALL DATA WILL BE LOST.
/// This command is only available in calibration mode.
///
///@{

struct ProdEraseStorage
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_PROD_ERASE_STORAGE;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    MediaSelector media;
    
};
void insert(MipSerializer& serializer, const ProdEraseStorage& self);
void extract(MipSerializer& serializer, ProdEraseStorage& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_led_control  None
/// This command allows direct control of the LED on the 3DM RTK. This command is only available in calibration mode or Production Test Mode.
///
///@{

struct LedControl
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_CONTROL;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    uint8_t primaryColor[3];
    uint8_t altColor[3];
    LedAction act;
    uint32_t period;
    
};
void insert(MipSerializer& serializer, const LedControl& self);
void extract(MipSerializer& serializer, LedControl& self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup cpp_modem_hard_reset  None
/// This command will clear the modem flash.  THIS MUST NOT BE DONE OFTEN AS IT CAN DAMAGE THE FLASH!
/// This command is only available in calibration mode.
///
///@{

struct ModemHardReset
{
    static const uint8_t DESCRIPTOR_SET = ::mscl::commands_rtk::DESCRIPTOR_SET;
    static const uint8_t FIELD_DESCRIPTOR = ::mscl::commands_rtk::CMD_MODEM_HARD_RESET;
    
    static const bool HAS_FUNCTION_SELECTOR = false;
    
    
};
void insert(MipSerializer& serializer, const ModemHardReset& self);
void extract(MipSerializer& serializer, ModemHardReset& self);

///@}
///

///@}
///@}
///
////////////////////////////////////////////////////////////////////////////////
} // namespace commands_rtk
} // namespace mscl

