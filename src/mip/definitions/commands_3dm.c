
#include "commands_3dm.h"

#include "../utils/serialization.h"
#include "../mip_interface.h"

#include <assert.h>


#ifdef __cplusplus
namespace mip {
namespace C {
extern "C" {

#endif // __cplusplus
struct mip_interface;
struct mip_serializer;
struct mip_field;


////////////////////////////////////////////////////////////////////////////////
// Shared Type Definitions
////////////////////////////////////////////////////////////////////////////////

void insert_mip_nmea_message(struct mip_serializer* serializer, const struct mip_nmea_message* self)
{
    insert_mip_nmea_message_message_id(serializer, self->message_id);
    
    insert_mip_nmea_message_talker_id(serializer, self->talker_id);
    
    insert_u8(serializer, self->source_desc_set);
    
    insert_u16(serializer, self->decimation);
    
}
void extract_mip_nmea_message(struct mip_serializer* serializer, struct mip_nmea_message* self)
{
    extract_mip_nmea_message_message_id(serializer, &self->message_id);
    
    extract_mip_nmea_message_talker_id(serializer, &self->talker_id);
    
    extract_u8(serializer, &self->source_desc_set);
    
    extract_u16(serializer, &self->decimation);
    
}

void insert_mip_nmea_message_message_id(struct mip_serializer* serializer, const enum mip_nmea_message_message_id self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_nmea_message_message_id(struct mip_serializer* serializer, enum mip_nmea_message_message_id* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_nmea_message_talker_id(struct mip_serializer* serializer, const enum mip_nmea_message_talker_id self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_nmea_message_talker_id(struct mip_serializer* serializer, enum mip_nmea_message_talker_id* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_sensor_range_type(struct mip_serializer* serializer, const enum mip_sensor_range_type self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_sensor_range_type(struct mip_serializer* serializer, enum mip_sensor_range_type* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}


////////////////////////////////////////////////////////////////////////////////
// Mip Fields
////////////////////////////////////////////////////////////////////////////////

void insert_mip_3dm_poll_imu_message_command(struct mip_serializer* serializer, const struct mip_3dm_poll_imu_message_command* self)
{
    insert_bool(serializer, self->suppress_ack);
    
    insert_u8(serializer, self->num_descriptors);
    
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        insert_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}
void extract_mip_3dm_poll_imu_message_command(struct mip_serializer* serializer, struct mip_3dm_poll_imu_message_command* self)
{
    extract_bool(serializer, &self->suppress_ack);
    
    assert(self->num_descriptors);
    extract_count(serializer, &self->num_descriptors, self->num_descriptors);
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        extract_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}

enum mip_cmd_result mip_3dm_poll_imu_message(struct mip_interface* device, bool suppress_ack, uint8_t num_descriptors, const struct mip_descriptor_rate* descriptors)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_bool(&serializer, suppress_ack);
    
    insert_u8(&serializer, num_descriptors);
    
    assert(descriptors);
    for(unsigned int i=0; i < num_descriptors; i++)
        insert_mip_descriptor_rate(&serializer, &descriptors[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_POLL_IMU_MESSAGE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_poll_gnss_message_command(struct mip_serializer* serializer, const struct mip_3dm_poll_gnss_message_command* self)
{
    insert_bool(serializer, self->suppress_ack);
    
    insert_u8(serializer, self->num_descriptors);
    
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        insert_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}
void extract_mip_3dm_poll_gnss_message_command(struct mip_serializer* serializer, struct mip_3dm_poll_gnss_message_command* self)
{
    extract_bool(serializer, &self->suppress_ack);
    
    assert(self->num_descriptors);
    extract_count(serializer, &self->num_descriptors, self->num_descriptors);
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        extract_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}

enum mip_cmd_result mip_3dm_poll_gnss_message(struct mip_interface* device, bool suppress_ack, uint8_t num_descriptors, const struct mip_descriptor_rate* descriptors)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_bool(&serializer, suppress_ack);
    
    insert_u8(&serializer, num_descriptors);
    
    assert(descriptors);
    for(unsigned int i=0; i < num_descriptors; i++)
        insert_mip_descriptor_rate(&serializer, &descriptors[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_POLL_GNSS_MESSAGE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_poll_filter_message_command(struct mip_serializer* serializer, const struct mip_3dm_poll_filter_message_command* self)
{
    insert_bool(serializer, self->suppress_ack);
    
    insert_u8(serializer, self->num_descriptors);
    
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        insert_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}
void extract_mip_3dm_poll_filter_message_command(struct mip_serializer* serializer, struct mip_3dm_poll_filter_message_command* self)
{
    extract_bool(serializer, &self->suppress_ack);
    
    assert(self->num_descriptors);
    extract_count(serializer, &self->num_descriptors, self->num_descriptors);
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        extract_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}

enum mip_cmd_result mip_3dm_poll_filter_message(struct mip_interface* device, bool suppress_ack, uint8_t num_descriptors, const struct mip_descriptor_rate* descriptors)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_bool(&serializer, suppress_ack);
    
    insert_u8(&serializer, num_descriptors);
    
    assert(descriptors);
    for(unsigned int i=0; i < num_descriptors; i++)
        insert_mip_descriptor_rate(&serializer, &descriptors[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_POLL_FILTER_MESSAGE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_imu_message_format_command(struct mip_serializer* serializer, const struct mip_3dm_imu_message_format_command* self)
{
    insert_u8(serializer, self->num_descriptors);
    
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        insert_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}
void extract_mip_3dm_imu_message_format_command(struct mip_serializer* serializer, struct mip_3dm_imu_message_format_command* self)
{
    assert(self->num_descriptors);
    extract_count(serializer, &self->num_descriptors, self->num_descriptors);
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        extract_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}

enum mip_cmd_result mip_3dm_write_imu_message_format(struct mip_interface* device, uint8_t num_descriptors, const struct mip_descriptor_rate* descriptors)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, num_descriptors);
    
    assert(descriptors);
    for(unsigned int i=0; i < num_descriptors; i++)
        insert_mip_descriptor_rate(&serializer, &descriptors[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_IMU_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_imu_message_format(struct mip_interface* device, uint8_t* num_descriptors_out, uint8_t num_descriptors_out_max, struct mip_descriptor_rate* descriptors_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_IMU_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_IMU_MESSAGE_FORMAT, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(num_descriptors_out);
        extract_count(&deserializer, num_descriptors_out, num_descriptors_out_max);
        
        assert(descriptors_out);
        assert(num_descriptors_out);
        for(unsigned int i=0; i < *num_descriptors_out; i++)
            extract_mip_descriptor_rate(&deserializer, &descriptors_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_imu_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_IMU_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_imu_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_IMU_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_imu_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_IMU_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_gps_message_format_command(struct mip_serializer* serializer, const struct mip_3dm_gps_message_format_command* self)
{
    insert_u8(serializer, self->num_descriptors);
    
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        insert_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}
void extract_mip_3dm_gps_message_format_command(struct mip_serializer* serializer, struct mip_3dm_gps_message_format_command* self)
{
    assert(self->num_descriptors);
    extract_count(serializer, &self->num_descriptors, self->num_descriptors);
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        extract_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}

enum mip_cmd_result mip_3dm_write_gps_message_format(struct mip_interface* device, uint8_t num_descriptors, const struct mip_descriptor_rate* descriptors)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, num_descriptors);
    
    assert(descriptors);
    for(unsigned int i=0; i < num_descriptors; i++)
        insert_mip_descriptor_rate(&serializer, &descriptors[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_gps_message_format(struct mip_interface* device, uint8_t* num_descriptors_out, uint8_t num_descriptors_out_max, struct mip_descriptor_rate* descriptors_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_GNSS_MESSAGE_FORMAT, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(num_descriptors_out);
        extract_count(&deserializer, num_descriptors_out, num_descriptors_out_max);
        
        assert(descriptors_out);
        assert(num_descriptors_out);
        for(unsigned int i=0; i < *num_descriptors_out; i++)
            extract_mip_descriptor_rate(&deserializer, &descriptors_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_gps_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_gps_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_gps_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_filter_message_format_command(struct mip_serializer* serializer, const struct mip_3dm_filter_message_format_command* self)
{
    insert_u8(serializer, self->num_descriptors);
    
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        insert_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}
void extract_mip_3dm_filter_message_format_command(struct mip_serializer* serializer, struct mip_3dm_filter_message_format_command* self)
{
    assert(self->num_descriptors);
    extract_count(serializer, &self->num_descriptors, self->num_descriptors);
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        extract_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}

enum mip_cmd_result mip_3dm_write_filter_message_format(struct mip_interface* device, uint8_t num_descriptors, const struct mip_descriptor_rate* descriptors)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, num_descriptors);
    
    assert(descriptors);
    for(unsigned int i=0; i < num_descriptors; i++)
        insert_mip_descriptor_rate(&serializer, &descriptors[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_FILTER_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_filter_message_format(struct mip_interface* device, uint8_t* num_descriptors_out, uint8_t num_descriptors_out_max, struct mip_descriptor_rate* descriptors_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_FILTER_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_FILTER_MESSAGE_FORMAT, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(num_descriptors_out);
        extract_count(&deserializer, num_descriptors_out, num_descriptors_out_max);
        
        assert(descriptors_out);
        assert(num_descriptors_out);
        for(unsigned int i=0; i < *num_descriptors_out; i++)
            extract_mip_descriptor_rate(&deserializer, &descriptors_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_filter_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_FILTER_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_filter_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_FILTER_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_filter_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_FILTER_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_imu_get_base_rate(struct mip_interface* device, uint16_t* rate_out)
{
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    uint8_t responseLength = sizeof(buffer);
    
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GET_IMU_BASE_RATE, NULL, 0, MIP_REPLY_DESC_3DM_IMU_BASE_RATE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(rate_out);
        extract_u16(&deserializer, rate_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_gps_get_base_rate(struct mip_interface* device, uint16_t* rate_out)
{
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    uint8_t responseLength = sizeof(buffer);
    
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GET_GNSS_BASE_RATE, NULL, 0, MIP_REPLY_DESC_3DM_GNSS_BASE_RATE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(rate_out);
        extract_u16(&deserializer, rate_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_filter_get_base_rate(struct mip_interface* device, uint16_t* rate_out)
{
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    uint8_t responseLength = sizeof(buffer);
    
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GET_FILTER_BASE_RATE, NULL, 0, MIP_REPLY_DESC_3DM_FILTER_BASE_RATE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(rate_out);
        extract_u16(&deserializer, rate_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
void insert_mip_3dm_poll_data_command(struct mip_serializer* serializer, const struct mip_3dm_poll_data_command* self)
{
    insert_u8(serializer, self->desc_set);
    
    insert_bool(serializer, self->suppress_ack);
    
    insert_u8(serializer, self->num_descriptors);
    
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        insert_u8(serializer, self->descriptors[i]);
    
}
void extract_mip_3dm_poll_data_command(struct mip_serializer* serializer, struct mip_3dm_poll_data_command* self)
{
    extract_u8(serializer, &self->desc_set);
    
    extract_bool(serializer, &self->suppress_ack);
    
    assert(self->num_descriptors);
    extract_count(serializer, &self->num_descriptors, self->num_descriptors);
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        extract_u8(serializer, &self->descriptors[i]);
    
}

enum mip_cmd_result mip_3dm_poll_data(struct mip_interface* device, uint8_t desc_set, bool suppress_ack, uint8_t num_descriptors, const uint8_t* descriptors)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_u8(&serializer, desc_set);
    
    insert_bool(&serializer, suppress_ack);
    
    insert_u8(&serializer, num_descriptors);
    
    assert(descriptors);
    for(unsigned int i=0; i < num_descriptors; i++)
        insert_u8(&serializer, descriptors[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_POLL_DATA, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_get_base_rate_command(struct mip_serializer* serializer, const struct mip_3dm_get_base_rate_command* self)
{
    insert_u8(serializer, self->desc_set);
    
}
void extract_mip_3dm_get_base_rate_command(struct mip_serializer* serializer, struct mip_3dm_get_base_rate_command* self)
{
    extract_u8(serializer, &self->desc_set);
    
}

enum mip_cmd_result mip_3dm_get_base_rate(struct mip_interface* device, uint8_t desc_set, uint16_t* rate_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GET_BASE_RATE, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_BASE_RATE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &desc_set);
        
        assert(rate_out);
        extract_u16(&deserializer, rate_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
void insert_mip_3dm_message_format_command(struct mip_serializer* serializer, const struct mip_3dm_message_format_command* self)
{
    insert_u8(serializer, self->desc_set);
    
    insert_u8(serializer, self->num_descriptors);
    
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        insert_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}
void extract_mip_3dm_message_format_command(struct mip_serializer* serializer, struct mip_3dm_message_format_command* self)
{
    extract_u8(serializer, &self->desc_set);
    
    assert(self->num_descriptors);
    extract_count(serializer, &self->num_descriptors, self->num_descriptors);
    
    for(unsigned int i=0; i < self->num_descriptors; i++)
        extract_mip_descriptor_rate(serializer, &self->descriptors[i]);
    
}

enum mip_cmd_result mip_3dm_write_message_format(struct mip_interface* device, uint8_t desc_set, uint8_t num_descriptors, const struct mip_descriptor_rate* descriptors)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, desc_set);
    
    insert_u8(&serializer, num_descriptors);
    
    assert(descriptors);
    for(unsigned int i=0; i < num_descriptors; i++)
        insert_mip_descriptor_rate(&serializer, &descriptors[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_message_format(struct mip_interface* device, uint8_t desc_set, uint8_t* num_descriptors_out, uint8_t num_descriptors_out_max, struct mip_descriptor_rate* descriptors_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_MESSAGE_FORMAT, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &desc_set);
        
        assert(num_descriptors_out);
        extract_count(&deserializer, num_descriptors_out, num_descriptors_out_max);
        
        assert(descriptors_out);
        assert(num_descriptors_out);
        for(unsigned int i=0; i < *num_descriptors_out; i++)
            extract_mip_descriptor_rate(&deserializer, &descriptors_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_message_format(struct mip_interface* device, uint8_t desc_set)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_message_format(struct mip_interface* device, uint8_t desc_set)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_message_format(struct mip_interface* device, uint8_t desc_set)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_nmea_poll_data_command(struct mip_serializer* serializer, const struct mip_3dm_nmea_poll_data_command* self)
{
    insert_bool(serializer, self->suppress_ack);
    
    insert_u8(serializer, self->count);
    
    
    for(unsigned int i=0; i < self->count; i++)
        insert_mip_nmea_message(serializer, &self->format_entries[i]);
    
}
void extract_mip_3dm_nmea_poll_data_command(struct mip_serializer* serializer, struct mip_3dm_nmea_poll_data_command* self)
{
    extract_bool(serializer, &self->suppress_ack);
    
    assert(self->count);
    extract_count(serializer, &self->count, self->count);
    
    for(unsigned int i=0; i < self->count; i++)
        extract_mip_nmea_message(serializer, &self->format_entries[i]);
    
}

enum mip_cmd_result mip_3dm_nmea_poll_data(struct mip_interface* device, bool suppress_ack, uint8_t count, const struct mip_nmea_message* format_entries)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_bool(&serializer, suppress_ack);
    
    insert_u8(&serializer, count);
    
    assert(format_entries);
    for(unsigned int i=0; i < count; i++)
        insert_mip_nmea_message(&serializer, &format_entries[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_POLL_NMEA_MESSAGE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_nmea_message_format_command(struct mip_serializer* serializer, const struct mip_3dm_nmea_message_format_command* self)
{
    insert_u8(serializer, self->count);
    
    
    for(unsigned int i=0; i < self->count; i++)
        insert_mip_nmea_message(serializer, &self->format_entries[i]);
    
}
void extract_mip_3dm_nmea_message_format_command(struct mip_serializer* serializer, struct mip_3dm_nmea_message_format_command* self)
{
    assert(self->count);
    extract_count(serializer, &self->count, self->count);
    
    for(unsigned int i=0; i < self->count; i++)
        extract_mip_nmea_message(serializer, &self->format_entries[i]);
    
}

enum mip_cmd_result mip_3dm_write_nmea_message_format(struct mip_interface* device, uint8_t count, const struct mip_nmea_message* format_entries)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, count);
    
    assert(format_entries);
    for(unsigned int i=0; i < count; i++)
        insert_mip_nmea_message(&serializer, &format_entries[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_NMEA_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_nmea_message_format(struct mip_interface* device, uint8_t* count_out, uint8_t count_out_max, struct mip_nmea_message* format_entries_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_NMEA_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_NMEA_MESSAGE_FORMAT, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(count_out);
        extract_count(&deserializer, count_out, count_out_max);
        
        assert(format_entries_out);
        assert(count_out);
        for(unsigned int i=0; i < *count_out; i++)
            extract_mip_nmea_message(&deserializer, &format_entries_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_nmea_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_NMEA_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_nmea_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_NMEA_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_nmea_message_format(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_NMEA_MESSAGE_FORMAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_device_settings_command(struct mip_serializer* serializer, const struct mip_3dm_device_settings_command* self)
{
    (void)serializer;
    (void)self;
}
void extract_mip_3dm_device_settings_command(struct mip_serializer* serializer, struct mip_3dm_device_settings_command* self)
{
    (void)serializer;
    (void)self;
}

enum mip_cmd_result mip_3dm_save_device_settings(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_DEVICE_STARTUP_SETTINGS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_device_settings(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_DEVICE_STARTUP_SETTINGS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_device_settings(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_DEVICE_STARTUP_SETTINGS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_uart_baudrate_command(struct mip_serializer* serializer, const struct mip_3dm_uart_baudrate_command* self)
{
    insert_u32(serializer, self->baud);
    
}
void extract_mip_3dm_uart_baudrate_command(struct mip_serializer* serializer, struct mip_3dm_uart_baudrate_command* self)
{
    extract_u32(serializer, &self->baud);
    
}

enum mip_cmd_result mip_3dm_write_uart_baudrate(struct mip_interface* device, uint32_t baud)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u32(&serializer, baud);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_UART_BAUDRATE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_uart_baudrate(struct mip_interface* device, uint32_t* baud_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_UART_BAUDRATE, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_UART_BAUDRATE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(baud_out);
        extract_u32(&deserializer, baud_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_uart_baudrate(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_UART_BAUDRATE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_uart_baudrate(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_UART_BAUDRATE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_uart_baudrate(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_UART_BAUDRATE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_factory_streaming_command(struct mip_serializer* serializer, const struct mip_3dm_factory_streaming_command* self)
{
    insert_mip_3dm_factory_streaming_command_action(serializer, self->action);
    
    insert_u8(serializer, self->reserved);
    
}
void extract_mip_3dm_factory_streaming_command(struct mip_serializer* serializer, struct mip_3dm_factory_streaming_command* self)
{
    extract_mip_3dm_factory_streaming_command_action(serializer, &self->action);
    
    extract_u8(serializer, &self->reserved);
    
}

void insert_mip_3dm_factory_streaming_command_action(struct mip_serializer* serializer, const enum mip_3dm_factory_streaming_command_action self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_factory_streaming_command_action(struct mip_serializer* serializer, enum mip_3dm_factory_streaming_command_action* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

enum mip_cmd_result mip_3dm_factory_streaming(struct mip_interface* device, enum mip_3dm_factory_streaming_command_action action, uint8_t reserved)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_3dm_factory_streaming_command_action(&serializer, action);
    
    insert_u8(&serializer, reserved);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_CONFIGURE_FACTORY_STREAMING, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_datastream_control_command(struct mip_serializer* serializer, const struct mip_3dm_datastream_control_command* self)
{
    insert_u8(serializer, self->desc_set);
    
    insert_bool(serializer, self->enable);
    
}
void extract_mip_3dm_datastream_control_command(struct mip_serializer* serializer, struct mip_3dm_datastream_control_command* self)
{
    extract_u8(serializer, &self->desc_set);
    
    extract_bool(serializer, &self->enable);
    
}

enum mip_cmd_result mip_3dm_write_datastream_control(struct mip_interface* device, uint8_t desc_set, bool enable)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, desc_set);
    
    insert_bool(&serializer, enable);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_CONTROL_DATA_STREAM, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_datastream_control(struct mip_interface* device, uint8_t desc_set, bool* enabled_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_CONTROL_DATA_STREAM, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_DATASTREAM_ENABLE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &desc_set);
        
        assert(enabled_out);
        extract_bool(&deserializer, enabled_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_datastream_control(struct mip_interface* device, uint8_t desc_set)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_CONTROL_DATA_STREAM, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_datastream_control(struct mip_interface* device, uint8_t desc_set)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_CONTROL_DATA_STREAM, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_datastream_control(struct mip_interface* device, uint8_t desc_set)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    insert_u8(&serializer, desc_set);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_CONTROL_DATA_STREAM, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_gnss_sbas_settings_command(struct mip_serializer* serializer, const struct mip_3dm_gnss_sbas_settings_command* self)
{
    insert_u8(serializer, self->enable_sbas);
    
    insert_mip_3dm_gnss_sbas_settings_command_sbasoptions(serializer, self->sbas_options);
    
    insert_u8(serializer, self->num_included_prns);
    
    
    for(unsigned int i=0; i < self->num_included_prns; i++)
        insert_u16(serializer, self->included_prns[i]);
    
}
void extract_mip_3dm_gnss_sbas_settings_command(struct mip_serializer* serializer, struct mip_3dm_gnss_sbas_settings_command* self)
{
    extract_u8(serializer, &self->enable_sbas);
    
    extract_mip_3dm_gnss_sbas_settings_command_sbasoptions(serializer, &self->sbas_options);
    
    assert(self->num_included_prns);
    extract_count(serializer, &self->num_included_prns, self->num_included_prns);
    
    for(unsigned int i=0; i < self->num_included_prns; i++)
        extract_u16(serializer, &self->included_prns[i]);
    
}

void insert_mip_3dm_gnss_sbas_settings_command_sbasoptions(struct mip_serializer* serializer, const enum mip_3dm_gnss_sbas_settings_command_sbasoptions self)
{
    return insert_u16(serializer, (uint16_t)(self));
}
void extract_mip_3dm_gnss_sbas_settings_command_sbasoptions(struct mip_serializer* serializer, enum mip_3dm_gnss_sbas_settings_command_sbasoptions* self)
{
    uint16_t tmp = 0;
    extract_u16(serializer, &tmp);
    *self = tmp;
}

enum mip_cmd_result mip_3dm_write_gnss_sbas_settings(struct mip_interface* device, uint8_t enable_sbas, enum mip_3dm_gnss_sbas_settings_command_sbasoptions sbas_options, uint8_t num_included_prns, const uint16_t* included_prns)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, enable_sbas);
    
    insert_mip_3dm_gnss_sbas_settings_command_sbasoptions(&serializer, sbas_options);
    
    insert_u8(&serializer, num_included_prns);
    
    assert(included_prns);
    for(unsigned int i=0; i < num_included_prns; i++)
        insert_u16(&serializer, included_prns[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_SBAS_SETTINGS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_gnss_sbas_settings(struct mip_interface* device, uint8_t* enable_sbas_out, enum mip_3dm_gnss_sbas_settings_command_sbasoptions* sbas_options_out, uint8_t* num_included_prns_out, uint8_t num_included_prns_out_max, uint16_t* included_prns_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_SBAS_SETTINGS, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_GNSS_SBAS_SETTINGS, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(enable_sbas_out);
        extract_u8(&deserializer, enable_sbas_out);
        
        assert(sbas_options_out);
        extract_mip_3dm_gnss_sbas_settings_command_sbasoptions(&deserializer, sbas_options_out);
        
        assert(num_included_prns_out);
        extract_count(&deserializer, num_included_prns_out, num_included_prns_out_max);
        
        assert(included_prns_out);
        assert(num_included_prns_out);
        for(unsigned int i=0; i < *num_included_prns_out; i++)
            extract_u16(&deserializer, &included_prns_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_gnss_sbas_settings(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_SBAS_SETTINGS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_gnss_sbas_settings(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_SBAS_SETTINGS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_gnss_sbas_settings(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_SBAS_SETTINGS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_gnss_time_assistance_command(struct mip_serializer* serializer, const struct mip_3dm_gnss_time_assistance_command* self)
{
    insert_double(serializer, self->tow);
    
    insert_u16(serializer, self->week_number);
    
    insert_float(serializer, self->accuracy);
    
}
void extract_mip_3dm_gnss_time_assistance_command(struct mip_serializer* serializer, struct mip_3dm_gnss_time_assistance_command* self)
{
    extract_double(serializer, &self->tow);
    
    extract_u16(serializer, &self->week_number);
    
    extract_float(serializer, &self->accuracy);
    
}

enum mip_cmd_result mip_3dm_write_gnss_time_assistance(struct mip_interface* device, double tow, uint16_t week_number, float accuracy)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_double(&serializer, tow);
    
    insert_u16(&serializer, week_number);
    
    insert_float(&serializer, accuracy);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_TIME_ASSISTANCE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_gnss_time_assistance(struct mip_interface* device, double* tow_out, uint16_t* week_number_out, float* accuracy_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GNSS_TIME_ASSISTANCE, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_GNSS_TIME_ASSISTANCE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(tow_out);
        extract_double(&deserializer, tow_out);
        
        assert(week_number_out);
        extract_u16(&deserializer, week_number_out);
        
        assert(accuracy_out);
        extract_float(&deserializer, accuracy_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
void insert_mip_3dm_adv_lowpass_filter_command(struct mip_serializer* serializer, const struct mip_3dm_adv_lowpass_filter_command* self)
{
    insert_u8(serializer, self->target_descriptor);
    
    insert_bool(serializer, self->enable);
    
    insert_bool(serializer, self->manual);
    
    insert_u16(serializer, self->frequency);
    
    insert_u8(serializer, self->reserved);
    
}
void extract_mip_3dm_adv_lowpass_filter_command(struct mip_serializer* serializer, struct mip_3dm_adv_lowpass_filter_command* self)
{
    extract_u8(serializer, &self->target_descriptor);
    
    extract_bool(serializer, &self->enable);
    
    extract_bool(serializer, &self->manual);
    
    extract_u16(serializer, &self->frequency);
    
    extract_u8(serializer, &self->reserved);
    
}

enum mip_cmd_result mip_3dm_write_adv_lowpass_filter(struct mip_interface* device, uint8_t target_descriptor, bool enable, bool manual, uint16_t frequency, uint8_t reserved)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, target_descriptor);
    
    insert_bool(&serializer, enable);
    
    insert_bool(&serializer, manual);
    
    insert_u16(&serializer, frequency);
    
    insert_u8(&serializer, reserved);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ADVANCED_DATA_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_adv_lowpass_filter(struct mip_interface* device, uint8_t target_descriptor, bool* enable_out, bool* manual_out, uint16_t* frequency_out, uint8_t* reserved_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_u8(&serializer, target_descriptor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ADVANCED_DATA_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_ADVANCED_DATA_FILTER, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &target_descriptor);
        
        assert(enable_out);
        extract_bool(&deserializer, enable_out);
        
        assert(manual_out);
        extract_bool(&deserializer, manual_out);
        
        assert(frequency_out);
        extract_u16(&deserializer, frequency_out);
        
        assert(reserved_out);
        extract_u8(&deserializer, reserved_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_adv_lowpass_filter(struct mip_interface* device, uint8_t target_descriptor)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    insert_u8(&serializer, target_descriptor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ADVANCED_DATA_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_adv_lowpass_filter(struct mip_interface* device, uint8_t target_descriptor)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    insert_u8(&serializer, target_descriptor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ADVANCED_DATA_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_adv_lowpass_filter(struct mip_interface* device, uint8_t target_descriptor)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    insert_u8(&serializer, target_descriptor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ADVANCED_DATA_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_pps_source_command(struct mip_serializer* serializer, const struct mip_3dm_pps_source_command* self)
{
    insert_mip_3dm_pps_source_command_source(serializer, self->source);
    
}
void extract_mip_3dm_pps_source_command(struct mip_serializer* serializer, struct mip_3dm_pps_source_command* self)
{
    extract_mip_3dm_pps_source_command_source(serializer, &self->source);
    
}

void insert_mip_3dm_pps_source_command_source(struct mip_serializer* serializer, const enum mip_3dm_pps_source_command_source self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_pps_source_command_source(struct mip_serializer* serializer, enum mip_3dm_pps_source_command_source* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

enum mip_cmd_result mip_3dm_write_pps_source(struct mip_interface* device, enum mip_3dm_pps_source_command_source source)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_mip_3dm_pps_source_command_source(&serializer, source);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_PPS_SOURCE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_pps_source(struct mip_interface* device, enum mip_3dm_pps_source_command_source* source_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_PPS_SOURCE, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_PPS_SOURCE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(source_out);
        extract_mip_3dm_pps_source_command_source(&deserializer, source_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_pps_source(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_PPS_SOURCE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_pps_source(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_PPS_SOURCE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_pps_source(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_PPS_SOURCE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_gpio_config_command(struct mip_serializer* serializer, const struct mip_3dm_gpio_config_command* self)
{
    insert_u8(serializer, self->pin);
    
    insert_mip_3dm_gpio_config_command_feature(serializer, self->feature);
    
    insert_mip_3dm_gpio_config_command_behavior(serializer, self->behavior);
    
    insert_mip_3dm_gpio_config_command_pin_mode(serializer, self->pin_mode);
    
}
void extract_mip_3dm_gpio_config_command(struct mip_serializer* serializer, struct mip_3dm_gpio_config_command* self)
{
    extract_u8(serializer, &self->pin);
    
    extract_mip_3dm_gpio_config_command_feature(serializer, &self->feature);
    
    extract_mip_3dm_gpio_config_command_behavior(serializer, &self->behavior);
    
    extract_mip_3dm_gpio_config_command_pin_mode(serializer, &self->pin_mode);
    
}

void insert_mip_3dm_gpio_config_command_feature(struct mip_serializer* serializer, const enum mip_3dm_gpio_config_command_feature self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_gpio_config_command_feature(struct mip_serializer* serializer, enum mip_3dm_gpio_config_command_feature* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_3dm_gpio_config_command_behavior(struct mip_serializer* serializer, const enum mip_3dm_gpio_config_command_behavior self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_gpio_config_command_behavior(struct mip_serializer* serializer, enum mip_3dm_gpio_config_command_behavior* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_3dm_gpio_config_command_pin_mode(struct mip_serializer* serializer, const enum mip_3dm_gpio_config_command_pin_mode self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_gpio_config_command_pin_mode(struct mip_serializer* serializer, enum mip_3dm_gpio_config_command_pin_mode* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

enum mip_cmd_result mip_3dm_write_gpio_config(struct mip_interface* device, uint8_t pin, enum mip_3dm_gpio_config_command_feature feature, enum mip_3dm_gpio_config_command_behavior behavior, enum mip_3dm_gpio_config_command_pin_mode pin_mode)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, pin);
    
    insert_mip_3dm_gpio_config_command_feature(&serializer, feature);
    
    insert_mip_3dm_gpio_config_command_behavior(&serializer, behavior);
    
    insert_mip_3dm_gpio_config_command_pin_mode(&serializer, pin_mode);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GPIO_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_gpio_config(struct mip_interface* device, uint8_t pin, enum mip_3dm_gpio_config_command_feature* feature_out, enum mip_3dm_gpio_config_command_behavior* behavior_out, enum mip_3dm_gpio_config_command_pin_mode* pin_mode_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_u8(&serializer, pin);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GPIO_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_GPIO_CONFIG, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &pin);
        
        assert(feature_out);
        extract_mip_3dm_gpio_config_command_feature(&deserializer, feature_out);
        
        assert(behavior_out);
        extract_mip_3dm_gpio_config_command_behavior(&deserializer, behavior_out);
        
        assert(pin_mode_out);
        extract_mip_3dm_gpio_config_command_pin_mode(&deserializer, pin_mode_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_gpio_config(struct mip_interface* device, uint8_t pin)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    insert_u8(&serializer, pin);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GPIO_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_gpio_config(struct mip_interface* device, uint8_t pin)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    insert_u8(&serializer, pin);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GPIO_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_gpio_config(struct mip_interface* device, uint8_t pin)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    insert_u8(&serializer, pin);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GPIO_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_gpio_state_command(struct mip_serializer* serializer, const struct mip_3dm_gpio_state_command* self)
{
    insert_u8(serializer, self->pin);
    
    insert_bool(serializer, self->state);
    
}
void extract_mip_3dm_gpio_state_command(struct mip_serializer* serializer, struct mip_3dm_gpio_state_command* self)
{
    extract_u8(serializer, &self->pin);
    
    extract_bool(serializer, &self->state);
    
}

enum mip_cmd_result mip_3dm_write_gpio_state(struct mip_interface* device, uint8_t pin, bool state)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, pin);
    
    insert_bool(&serializer, state);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GPIO_STATE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_gpio_state(struct mip_interface* device, uint8_t pin, bool* state_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_u8(&serializer, pin);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GPIO_STATE, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_GPIO_STATE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &pin);
        
        assert(state_out);
        extract_bool(&deserializer, state_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
void insert_mip_3dm_odometer_command(struct mip_serializer* serializer, const struct mip_3dm_odometer_command* self)
{
    insert_mip_3dm_odometer_command_mode(serializer, self->mode);
    
    insert_float(serializer, self->scaling);
    
    insert_float(serializer, self->uncertainty);
    
}
void extract_mip_3dm_odometer_command(struct mip_serializer* serializer, struct mip_3dm_odometer_command* self)
{
    extract_mip_3dm_odometer_command_mode(serializer, &self->mode);
    
    extract_float(serializer, &self->scaling);
    
    extract_float(serializer, &self->uncertainty);
    
}

void insert_mip_3dm_odometer_command_mode(struct mip_serializer* serializer, const enum mip_3dm_odometer_command_mode self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_odometer_command_mode(struct mip_serializer* serializer, enum mip_3dm_odometer_command_mode* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

enum mip_cmd_result mip_3dm_write_odometer(struct mip_interface* device, enum mip_3dm_odometer_command_mode mode, float scaling, float uncertainty)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_mip_3dm_odometer_command_mode(&serializer, mode);
    
    insert_float(&serializer, scaling);
    
    insert_float(&serializer, uncertainty);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ODOMETER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_odometer(struct mip_interface* device, enum mip_3dm_odometer_command_mode* mode_out, float* scaling_out, float* uncertainty_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ODOMETER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_ODOMETER_CONFIG, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(mode_out);
        extract_mip_3dm_odometer_command_mode(&deserializer, mode_out);
        
        assert(scaling_out);
        extract_float(&deserializer, scaling_out);
        
        assert(uncertainty_out);
        extract_float(&deserializer, uncertainty_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_odometer(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ODOMETER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_odometer(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ODOMETER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_odometer(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ODOMETER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_get_event_support_command(struct mip_serializer* serializer, const struct mip_3dm_get_event_support_command* self)
{
    insert_mip_3dm_get_event_support_command_query(serializer, self->query);
    
}
void extract_mip_3dm_get_event_support_command(struct mip_serializer* serializer, struct mip_3dm_get_event_support_command* self)
{
    extract_mip_3dm_get_event_support_command_query(serializer, &self->query);
    
}

void insert_mip_3dm_get_event_support_command_query(struct mip_serializer* serializer, const enum mip_3dm_get_event_support_command_query self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_get_event_support_command_query(struct mip_serializer* serializer, enum mip_3dm_get_event_support_command_query* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_3dm_get_event_support_command_info(struct mip_serializer* serializer, const struct mip_3dm_get_event_support_command_info* self)
{
    insert_u8(serializer, self->type);
    
    insert_u8(serializer, self->count);
    
}
void extract_mip_3dm_get_event_support_command_info(struct mip_serializer* serializer, struct mip_3dm_get_event_support_command_info* self)
{
    extract_u8(serializer, &self->type);
    
    extract_u8(serializer, &self->count);
    
}

enum mip_cmd_result mip_3dm_get_event_support(struct mip_interface* device, enum mip_3dm_get_event_support_command_query query, uint8_t* max_instances_out, uint8_t* num_entries_out, uint8_t num_entries_out_max, struct mip_3dm_get_event_support_command_info* entries_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_3dm_get_event_support_command_query(&serializer, query);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_SUPPORT, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_EVENT_SUPPORT, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_mip_3dm_get_event_support_command_query(&deserializer, &query);
        
        assert(max_instances_out);
        extract_u8(&deserializer, max_instances_out);
        
        assert(num_entries_out);
        extract_count(&deserializer, num_entries_out, num_entries_out_max);
        
        assert(entries_out);
        assert(num_entries_out);
        for(unsigned int i=0; i < *num_entries_out; i++)
            extract_mip_3dm_get_event_support_command_info(&deserializer, &entries_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
void insert_mip_3dm_event_control_command(struct mip_serializer* serializer, const struct mip_3dm_event_control_command* self)
{
    insert_u8(serializer, self->instance);
    
    insert_mip_3dm_event_control_command_mode(serializer, self->mode);
    
}
void extract_mip_3dm_event_control_command(struct mip_serializer* serializer, struct mip_3dm_event_control_command* self)
{
    extract_u8(serializer, &self->instance);
    
    extract_mip_3dm_event_control_command_mode(serializer, &self->mode);
    
}

void insert_mip_3dm_event_control_command_mode(struct mip_serializer* serializer, const enum mip_3dm_event_control_command_mode self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_event_control_command_mode(struct mip_serializer* serializer, enum mip_3dm_event_control_command_mode* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

enum mip_cmd_result mip_3dm_write_event_control(struct mip_interface* device, uint8_t instance, enum mip_3dm_event_control_command_mode mode)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, instance);
    
    insert_mip_3dm_event_control_command_mode(&serializer, mode);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_CONTROL, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_event_control(struct mip_interface* device, uint8_t instance, enum mip_3dm_event_control_command_mode* mode_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_CONTROL, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_EVENT_CONTROL, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &instance);
        
        assert(mode_out);
        extract_mip_3dm_event_control_command_mode(&deserializer, mode_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_event_control(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_CONTROL, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_event_control(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_CONTROL, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_event_control(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_CONTROL, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_get_event_trigger_status_command(struct mip_serializer* serializer, const struct mip_3dm_get_event_trigger_status_command* self)
{
    insert_u8(serializer, self->requested_count);
    
    
    for(unsigned int i=0; i < self->requested_count; i++)
        insert_u8(serializer, self->requested_instances[i]);
    
}
void extract_mip_3dm_get_event_trigger_status_command(struct mip_serializer* serializer, struct mip_3dm_get_event_trigger_status_command* self)
{
    assert(self->requested_count);
    extract_count(serializer, &self->requested_count, self->requested_count);
    
    for(unsigned int i=0; i < self->requested_count; i++)
        extract_u8(serializer, &self->requested_instances[i]);
    
}

void insert_mip_3dm_get_event_trigger_status_command_status(struct mip_serializer* serializer, const enum mip_3dm_get_event_trigger_status_command_status self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_get_event_trigger_status_command_status(struct mip_serializer* serializer, enum mip_3dm_get_event_trigger_status_command_status* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_3dm_get_event_trigger_status_command_entry(struct mip_serializer* serializer, const struct mip_3dm_get_event_trigger_status_command_entry* self)
{
    insert_u8(serializer, self->type);
    
    insert_mip_3dm_get_event_trigger_status_command_status(serializer, self->status);
    
}
void extract_mip_3dm_get_event_trigger_status_command_entry(struct mip_serializer* serializer, struct mip_3dm_get_event_trigger_status_command_entry* self)
{
    extract_u8(serializer, &self->type);
    
    extract_mip_3dm_get_event_trigger_status_command_status(serializer, &self->status);
    
}

enum mip_cmd_result mip_3dm_get_event_trigger_status(struct mip_interface* device, uint8_t requested_count, const uint8_t* requested_instances, uint8_t* count_out, uint8_t count_out_max, struct mip_3dm_get_event_trigger_status_command_entry* triggers_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_u8(&serializer, requested_count);
    
    assert(requested_instances);
    for(unsigned int i=0; i < requested_count; i++)
        insert_u8(&serializer, requested_instances[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_TRIGGER_STATUS, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_EVENT_TRIGGER_STATUS, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(count_out);
        extract_count(&deserializer, count_out, count_out_max);
        
        assert(triggers_out);
        assert(count_out);
        for(unsigned int i=0; i < *count_out; i++)
            extract_mip_3dm_get_event_trigger_status_command_entry(&deserializer, &triggers_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
void insert_mip_3dm_get_event_action_status_command(struct mip_serializer* serializer, const struct mip_3dm_get_event_action_status_command* self)
{
    insert_u8(serializer, self->requested_count);
    
    
    for(unsigned int i=0; i < self->requested_count; i++)
        insert_u8(serializer, self->requested_instances[i]);
    
}
void extract_mip_3dm_get_event_action_status_command(struct mip_serializer* serializer, struct mip_3dm_get_event_action_status_command* self)
{
    assert(self->requested_count);
    extract_count(serializer, &self->requested_count, self->requested_count);
    
    for(unsigned int i=0; i < self->requested_count; i++)
        extract_u8(serializer, &self->requested_instances[i]);
    
}

void insert_mip_3dm_get_event_action_status_command_entry(struct mip_serializer* serializer, const struct mip_3dm_get_event_action_status_command_entry* self)
{
    insert_u8(serializer, self->action_type);
    
    insert_u8(serializer, self->trigger_id);
    
}
void extract_mip_3dm_get_event_action_status_command_entry(struct mip_serializer* serializer, struct mip_3dm_get_event_action_status_command_entry* self)
{
    extract_u8(serializer, &self->action_type);
    
    extract_u8(serializer, &self->trigger_id);
    
}

enum mip_cmd_result mip_3dm_get_event_action_status(struct mip_interface* device, uint8_t requested_count, const uint8_t* requested_instances, uint8_t* count_out, uint8_t count_out_max, struct mip_3dm_get_event_action_status_command_entry* actions_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_u8(&serializer, requested_count);
    
    assert(requested_instances);
    for(unsigned int i=0; i < requested_count; i++)
        insert_u8(&serializer, requested_instances[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_ACTION_STATUS, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_EVENT_ACTION_STATUS, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(count_out);
        extract_count(&deserializer, count_out, count_out_max);
        
        assert(actions_out);
        assert(count_out);
        for(unsigned int i=0; i < *count_out; i++)
            extract_mip_3dm_get_event_action_status_command_entry(&deserializer, &actions_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
void insert_mip_3dm_event_trigger_command(struct mip_serializer* serializer, const struct mip_3dm_event_trigger_command* self)
{
    insert_u8(serializer, self->instance);
    
    insert_mip_3dm_event_trigger_command_type(serializer, self->type);
    
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_GPIO )
    {
        insert_mip_3dm_event_trigger_command_gpio_params(serializer, &self->parameters.gpio);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_THRESHOLD )
    {
        insert_mip_3dm_event_trigger_command_threshold_params(serializer, &self->parameters.threshold);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_COMBINATION )
    {
        insert_mip_3dm_event_trigger_command_combination_params(serializer, &self->parameters.combination);
        
    }
}
void extract_mip_3dm_event_trigger_command(struct mip_serializer* serializer, struct mip_3dm_event_trigger_command* self)
{
    extract_u8(serializer, &self->instance);
    
    extract_mip_3dm_event_trigger_command_type(serializer, &self->type);
    
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_GPIO )
    {
        extract_mip_3dm_event_trigger_command_gpio_params(serializer, &self->parameters.gpio);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_THRESHOLD )
    {
        extract_mip_3dm_event_trigger_command_threshold_params(serializer, &self->parameters.threshold);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_COMBINATION )
    {
        extract_mip_3dm_event_trigger_command_combination_params(serializer, &self->parameters.combination);
        
    }
}

void insert_mip_3dm_event_trigger_command_gpio_params(struct mip_serializer* serializer, const struct mip_3dm_event_trigger_command_gpio_params* self)
{
    insert_u8(serializer, self->pin);
    
    insert_mip_3dm_event_trigger_command_gpio_params_mode(serializer, self->mode);
    
}
void extract_mip_3dm_event_trigger_command_gpio_params(struct mip_serializer* serializer, struct mip_3dm_event_trigger_command_gpio_params* self)
{
    extract_u8(serializer, &self->pin);
    
    extract_mip_3dm_event_trigger_command_gpio_params_mode(serializer, &self->mode);
    
}

void insert_mip_3dm_event_trigger_command_gpio_params_mode(struct mip_serializer* serializer, const enum mip_3dm_event_trigger_command_gpio_params_mode self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_event_trigger_command_gpio_params_mode(struct mip_serializer* serializer, enum mip_3dm_event_trigger_command_gpio_params_mode* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_3dm_event_trigger_command_threshold_params(struct mip_serializer* serializer, const struct mip_3dm_event_trigger_command_threshold_params* self)
{
    insert_u8(serializer, self->desc_set);
    
    insert_u8(serializer, self->field_desc);
    
    insert_u8(serializer, self->param_id);
    
    insert_mip_3dm_event_trigger_command_threshold_params_type(serializer, self->type);
    
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_THRESHOLD_PARAMS_TYPE_WINDOW )
    {
        insert_double(serializer, self->low_thres);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_THRESHOLD_PARAMS_TYPE_INTERVAL )
    {
        insert_double(serializer, self->int_thres);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_THRESHOLD_PARAMS_TYPE_WINDOW )
    {
        insert_double(serializer, self->high_thres);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_THRESHOLD_PARAMS_TYPE_INTERVAL )
    {
        insert_double(serializer, self->interval);
        
    }
}
void extract_mip_3dm_event_trigger_command_threshold_params(struct mip_serializer* serializer, struct mip_3dm_event_trigger_command_threshold_params* self)
{
    extract_u8(serializer, &self->desc_set);
    
    extract_u8(serializer, &self->field_desc);
    
    extract_u8(serializer, &self->param_id);
    
    extract_mip_3dm_event_trigger_command_threshold_params_type(serializer, &self->type);
    
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_THRESHOLD_PARAMS_TYPE_WINDOW )
    {
        extract_double(serializer, &self->low_thres);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_THRESHOLD_PARAMS_TYPE_INTERVAL )
    {
        extract_double(serializer, &self->int_thres);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_THRESHOLD_PARAMS_TYPE_WINDOW )
    {
        extract_double(serializer, &self->high_thres);
        
    }
    if( self->type == MIP_3DM_EVENT_TRIGGER_COMMAND_THRESHOLD_PARAMS_TYPE_INTERVAL )
    {
        extract_double(serializer, &self->interval);
        
    }
}

void insert_mip_3dm_event_trigger_command_threshold_params_type(struct mip_serializer* serializer, const enum mip_3dm_event_trigger_command_threshold_params_type self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_event_trigger_command_threshold_params_type(struct mip_serializer* serializer, enum mip_3dm_event_trigger_command_threshold_params_type* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_3dm_event_trigger_command_combination_params(struct mip_serializer* serializer, const struct mip_3dm_event_trigger_command_combination_params* self)
{
    insert_u16(serializer, self->logic_table);
    
    for(unsigned int i=0; i < 4; i++)
        insert_u8(serializer, self->input_triggers[i]);
    
}
void extract_mip_3dm_event_trigger_command_combination_params(struct mip_serializer* serializer, struct mip_3dm_event_trigger_command_combination_params* self)
{
    extract_u16(serializer, &self->logic_table);
    
    for(unsigned int i=0; i < 4; i++)
        extract_u8(serializer, &self->input_triggers[i]);
    
}

void insert_mip_3dm_event_trigger_command_type(struct mip_serializer* serializer, const enum mip_3dm_event_trigger_command_type self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_event_trigger_command_type(struct mip_serializer* serializer, enum mip_3dm_event_trigger_command_type* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

enum mip_cmd_result mip_3dm_write_event_trigger(struct mip_interface* device, uint8_t instance, enum mip_3dm_event_trigger_command_type type, const union mip_3dm_event_trigger_command_parameters* parameters)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, instance);
    
    insert_mip_3dm_event_trigger_command_type(&serializer, type);
    
    if( type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_GPIO )
    {
        insert_mip_3dm_event_trigger_command_gpio_params(&serializer, &parameters->gpio);
        
    }
    if( type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_THRESHOLD )
    {
        insert_mip_3dm_event_trigger_command_threshold_params(&serializer, &parameters->threshold);
        
    }
    if( type == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_COMBINATION )
    {
        insert_mip_3dm_event_trigger_command_combination_params(&serializer, &parameters->combination);
        
    }
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_TRIGGER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_event_trigger(struct mip_interface* device, uint8_t instance, enum mip_3dm_event_trigger_command_type* type_out, union mip_3dm_event_trigger_command_parameters* parameters_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_TRIGGER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_EVENT_TRIGGER_CONFIG, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &instance);
        
        assert(type_out);
        extract_mip_3dm_event_trigger_command_type(&deserializer, type_out);
        
        if( *type_out == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_GPIO )
        {
            extract_mip_3dm_event_trigger_command_gpio_params(&deserializer, &parameters_out->gpio);
            
        }
        if( *type_out == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_THRESHOLD )
        {
            extract_mip_3dm_event_trigger_command_threshold_params(&deserializer, &parameters_out->threshold);
            
        }
        if( *type_out == MIP_3DM_EVENT_TRIGGER_COMMAND_TYPE_COMBINATION )
        {
            extract_mip_3dm_event_trigger_command_combination_params(&deserializer, &parameters_out->combination);
            
        }
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_event_trigger(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_TRIGGER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_event_trigger(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_TRIGGER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_event_trigger(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_TRIGGER_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_event_action_command(struct mip_serializer* serializer, const struct mip_3dm_event_action_command* self)
{
    insert_u8(serializer, self->instance);
    
    insert_u8(serializer, self->trigger);
    
    insert_mip_3dm_event_action_command_type(serializer, self->type);
    
    if( self->type == MIP_3DM_EVENT_ACTION_COMMAND_TYPE_GPIO )
    {
        insert_mip_3dm_event_action_command_gpio_params(serializer, &self->parameters.gpio);
        
    }
    if( self->type == MIP_3DM_EVENT_ACTION_COMMAND_TYPE_MESSAGE )
    {
        insert_mip_3dm_event_action_command_message_params(serializer, &self->parameters.message);
        
    }
}
void extract_mip_3dm_event_action_command(struct mip_serializer* serializer, struct mip_3dm_event_action_command* self)
{
    extract_u8(serializer, &self->instance);
    
    extract_u8(serializer, &self->trigger);
    
    extract_mip_3dm_event_action_command_type(serializer, &self->type);
    
    if( self->type == MIP_3DM_EVENT_ACTION_COMMAND_TYPE_GPIO )
    {
        extract_mip_3dm_event_action_command_gpio_params(serializer, &self->parameters.gpio);
        
    }
    if( self->type == MIP_3DM_EVENT_ACTION_COMMAND_TYPE_MESSAGE )
    {
        extract_mip_3dm_event_action_command_message_params(serializer, &self->parameters.message);
        
    }
}

void insert_mip_3dm_event_action_command_gpio_params(struct mip_serializer* serializer, const struct mip_3dm_event_action_command_gpio_params* self)
{
    insert_u8(serializer, self->pin);
    
    insert_mip_3dm_event_action_command_gpio_params_mode(serializer, self->mode);
    
}
void extract_mip_3dm_event_action_command_gpio_params(struct mip_serializer* serializer, struct mip_3dm_event_action_command_gpio_params* self)
{
    extract_u8(serializer, &self->pin);
    
    extract_mip_3dm_event_action_command_gpio_params_mode(serializer, &self->mode);
    
}

void insert_mip_3dm_event_action_command_gpio_params_mode(struct mip_serializer* serializer, const enum mip_3dm_event_action_command_gpio_params_mode self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_event_action_command_gpio_params_mode(struct mip_serializer* serializer, enum mip_3dm_event_action_command_gpio_params_mode* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

void insert_mip_3dm_event_action_command_message_params(struct mip_serializer* serializer, const struct mip_3dm_event_action_command_message_params* self)
{
    insert_u8(serializer, self->desc_set);
    
    insert_u16(serializer, self->decimation);
    
    insert_u8(serializer, self->num_fields);
    
    
    for(unsigned int i=0; i < self->num_fields; i++)
        insert_u8(serializer, self->descriptors[i]);
    
}
void extract_mip_3dm_event_action_command_message_params(struct mip_serializer* serializer, struct mip_3dm_event_action_command_message_params* self)
{
    extract_u8(serializer, &self->desc_set);
    
    extract_u16(serializer, &self->decimation);
    
    assert(self->num_fields);
    extract_count(serializer, &self->num_fields, self->num_fields);
    
    for(unsigned int i=0; i < self->num_fields; i++)
        extract_u8(serializer, &self->descriptors[i]);
    
}

void insert_mip_3dm_event_action_command_type(struct mip_serializer* serializer, const enum mip_3dm_event_action_command_type self)
{
    return insert_u8(serializer, (uint8_t)(self));
}
void extract_mip_3dm_event_action_command_type(struct mip_serializer* serializer, enum mip_3dm_event_action_command_type* self)
{
    uint8_t tmp = 0;
    extract_u8(serializer, &tmp);
    *self = tmp;
}

enum mip_cmd_result mip_3dm_write_event_action(struct mip_interface* device, uint8_t instance, uint8_t trigger, enum mip_3dm_event_action_command_type type, const union mip_3dm_event_action_command_parameters* parameters)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_u8(&serializer, instance);
    
    insert_u8(&serializer, trigger);
    
    insert_mip_3dm_event_action_command_type(&serializer, type);
    
    if( type == MIP_3DM_EVENT_ACTION_COMMAND_TYPE_GPIO )
    {
        insert_mip_3dm_event_action_command_gpio_params(&serializer, &parameters->gpio);
        
    }
    if( type == MIP_3DM_EVENT_ACTION_COMMAND_TYPE_MESSAGE )
    {
        insert_mip_3dm_event_action_command_message_params(&serializer, &parameters->message);
        
    }
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_ACTION_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_event_action(struct mip_interface* device, uint8_t instance, uint8_t* trigger_out, enum mip_3dm_event_action_command_type* type_out, union mip_3dm_event_action_command_parameters* parameters_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_ACTION_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_EVENT_ACTION_CONFIG, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_u8(&deserializer, &instance);
        
        assert(trigger_out);
        extract_u8(&deserializer, trigger_out);
        
        assert(type_out);
        extract_mip_3dm_event_action_command_type(&deserializer, type_out);
        
        if( *type_out == MIP_3DM_EVENT_ACTION_COMMAND_TYPE_GPIO )
        {
            extract_mip_3dm_event_action_command_gpio_params(&deserializer, &parameters_out->gpio);
            
        }
        if( *type_out == MIP_3DM_EVENT_ACTION_COMMAND_TYPE_MESSAGE )
        {
            extract_mip_3dm_event_action_command_message_params(&deserializer, &parameters_out->message);
            
        }
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_event_action(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_ACTION_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_event_action(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_ACTION_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_event_action(struct mip_interface* device, uint8_t instance)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    insert_u8(&serializer, instance);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_EVENT_ACTION_CONFIG, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_accel_bias_command(struct mip_serializer* serializer, const struct mip_3dm_accel_bias_command* self)
{
    for(unsigned int i=0; i < 3; i++)
        insert_float(serializer, self->bias[i]);
    
}
void extract_mip_3dm_accel_bias_command(struct mip_serializer* serializer, struct mip_3dm_accel_bias_command* self)
{
    for(unsigned int i=0; i < 3; i++)
        extract_float(serializer, &self->bias[i]);
    
}

enum mip_cmd_result mip_3dm_write_accel_bias(struct mip_interface* device, const float* bias)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    assert(bias);
    for(unsigned int i=0; i < 3; i++)
        insert_float(&serializer, bias[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ACCEL_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_accel_bias(struct mip_interface* device, float* bias_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ACCEL_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_ACCEL_BIAS_VECTOR, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(bias_out);
        for(unsigned int i=0; i < 3; i++)
            extract_float(&deserializer, &bias_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_accel_bias(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ACCEL_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_accel_bias(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ACCEL_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_accel_bias(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_ACCEL_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_gyro_bias_command(struct mip_serializer* serializer, const struct mip_3dm_gyro_bias_command* self)
{
    for(unsigned int i=0; i < 3; i++)
        insert_float(serializer, self->bias[i]);
    
}
void extract_mip_3dm_gyro_bias_command(struct mip_serializer* serializer, struct mip_3dm_gyro_bias_command* self)
{
    for(unsigned int i=0; i < 3; i++)
        extract_float(serializer, &self->bias[i]);
    
}

enum mip_cmd_result mip_3dm_write_gyro_bias(struct mip_interface* device, const float* bias)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    assert(bias);
    for(unsigned int i=0; i < 3; i++)
        insert_float(&serializer, bias[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GYRO_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_gyro_bias(struct mip_interface* device, float* bias_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GYRO_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_GYRO_BIAS_VECTOR, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(bias_out);
        for(unsigned int i=0; i < 3; i++)
            extract_float(&deserializer, &bias_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_gyro_bias(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GYRO_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_gyro_bias(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GYRO_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_gyro_bias(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_GYRO_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_capture_gyro_bias_command(struct mip_serializer* serializer, const struct mip_3dm_capture_gyro_bias_command* self)
{
    insert_u16(serializer, self->averaging_time_ms);
    
}
void extract_mip_3dm_capture_gyro_bias_command(struct mip_serializer* serializer, struct mip_3dm_capture_gyro_bias_command* self)
{
    extract_u16(serializer, &self->averaging_time_ms);
    
}

enum mip_cmd_result mip_3dm_capture_gyro_bias(struct mip_interface* device, uint16_t averaging_time_ms, float* bias_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_u16(&serializer, averaging_time_ms);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_CAPTURE_GYRO_BIAS, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_GYRO_BIAS_VECTOR, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(bias_out);
        for(unsigned int i=0; i < 3; i++)
            extract_float(&deserializer, &bias_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
void insert_mip_3dm_mag_hard_iron_offset_command(struct mip_serializer* serializer, const struct mip_3dm_mag_hard_iron_offset_command* self)
{
    for(unsigned int i=0; i < 3; i++)
        insert_float(serializer, self->offset[i]);
    
}
void extract_mip_3dm_mag_hard_iron_offset_command(struct mip_serializer* serializer, struct mip_3dm_mag_hard_iron_offset_command* self)
{
    for(unsigned int i=0; i < 3; i++)
        extract_float(serializer, &self->offset[i]);
    
}

enum mip_cmd_result mip_3dm_write_mag_hard_iron_offset(struct mip_interface* device, const float* offset)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    assert(offset);
    for(unsigned int i=0; i < 3; i++)
        insert_float(&serializer, offset[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_HARD_IRON_OFFSET, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_mag_hard_iron_offset(struct mip_interface* device, float* offset_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_HARD_IRON_OFFSET, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_HARD_IRON_OFFSET_VECTOR, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(offset_out);
        for(unsigned int i=0; i < 3; i++)
            extract_float(&deserializer, &offset_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_mag_hard_iron_offset(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_HARD_IRON_OFFSET, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_mag_hard_iron_offset(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_HARD_IRON_OFFSET, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_mag_hard_iron_offset(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_HARD_IRON_OFFSET, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_mag_soft_iron_matrix_command(struct mip_serializer* serializer, const struct mip_3dm_mag_soft_iron_matrix_command* self)
{
    for(unsigned int i=0; i < 9; i++)
        insert_float(serializer, self->offset[i]);
    
}
void extract_mip_3dm_mag_soft_iron_matrix_command(struct mip_serializer* serializer, struct mip_3dm_mag_soft_iron_matrix_command* self)
{
    for(unsigned int i=0; i < 9; i++)
        extract_float(serializer, &self->offset[i]);
    
}

enum mip_cmd_result mip_3dm_write_mag_soft_iron_matrix(struct mip_interface* device, const float* offset)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    assert(offset);
    for(unsigned int i=0; i < 9; i++)
        insert_float(&serializer, offset[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SOFT_IRON_MATRIX, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_mag_soft_iron_matrix(struct mip_interface* device, float* offset_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SOFT_IRON_MATRIX, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_SOFT_IRON_COMP_MATRIX, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(offset_out);
        for(unsigned int i=0; i < 9; i++)
            extract_float(&deserializer, &offset_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_mag_soft_iron_matrix(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SOFT_IRON_MATRIX, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_mag_soft_iron_matrix(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SOFT_IRON_MATRIX, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_mag_soft_iron_matrix(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SOFT_IRON_MATRIX, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_sensor_2_vehicle_transform_euler_command(struct mip_serializer* serializer, const struct mip_3dm_sensor_2_vehicle_transform_euler_command* self)
{
    insert_float(serializer, self->roll);
    
    insert_float(serializer, self->pitch);
    
    insert_float(serializer, self->yaw);
    
}
void extract_mip_3dm_sensor_2_vehicle_transform_euler_command(struct mip_serializer* serializer, struct mip_3dm_sensor_2_vehicle_transform_euler_command* self)
{
    extract_float(serializer, &self->roll);
    
    extract_float(serializer, &self->pitch);
    
    extract_float(serializer, &self->yaw);
    
}

enum mip_cmd_result mip_3dm_write_sensor_2_vehicle_transform_euler(struct mip_interface* device, float roll, float pitch, float yaw)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_float(&serializer, roll);
    
    insert_float(&serializer, pitch);
    
    insert_float(&serializer, yaw);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_EUL, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_sensor_2_vehicle_transform_euler(struct mip_interface* device, float* roll_out, float* pitch_out, float* yaw_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_EUL, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_EUL, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(roll_out);
        extract_float(&deserializer, roll_out);
        
        assert(pitch_out);
        extract_float(&deserializer, pitch_out);
        
        assert(yaw_out);
        extract_float(&deserializer, yaw_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_sensor_2_vehicle_transform_euler(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_EUL, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_sensor_2_vehicle_transform_euler(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_EUL, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_sensor_2_vehicle_transform_euler(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_EUL, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_sensor_2_vehicle_transform_quaternion_command(struct mip_serializer* serializer, const struct mip_3dm_sensor_2_vehicle_transform_quaternion_command* self)
{
    for(unsigned int i=0; i < 4; i++)
        insert_float(serializer, self->q[i]);
    
}
void extract_mip_3dm_sensor_2_vehicle_transform_quaternion_command(struct mip_serializer* serializer, struct mip_3dm_sensor_2_vehicle_transform_quaternion_command* self)
{
    for(unsigned int i=0; i < 4; i++)
        extract_float(serializer, &self->q[i]);
    
}

enum mip_cmd_result mip_3dm_write_sensor_2_vehicle_transform_quaternion(struct mip_interface* device, const float* q)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    assert(q);
    for(unsigned int i=0; i < 4; i++)
        insert_float(&serializer, q[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_QUAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_sensor_2_vehicle_transform_quaternion(struct mip_interface* device, float* q_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_QUAT, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_QUAT, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(q_out);
        for(unsigned int i=0; i < 4; i++)
            extract_float(&deserializer, &q_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_sensor_2_vehicle_transform_quaternion(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_QUAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_sensor_2_vehicle_transform_quaternion(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_QUAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_sensor_2_vehicle_transform_quaternion(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_QUAT, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_sensor_2_vehicle_transform_dcm_command(struct mip_serializer* serializer, const struct mip_3dm_sensor_2_vehicle_transform_dcm_command* self)
{
    for(unsigned int i=0; i < 9; i++)
        insert_float(serializer, self->dcm[i]);
    
}
void extract_mip_3dm_sensor_2_vehicle_transform_dcm_command(struct mip_serializer* serializer, struct mip_3dm_sensor_2_vehicle_transform_dcm_command* self)
{
    for(unsigned int i=0; i < 9; i++)
        extract_float(serializer, &self->dcm[i]);
    
}

enum mip_cmd_result mip_3dm_write_sensor_2_vehicle_transform_dcm(struct mip_interface* device, const float* dcm)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    assert(dcm);
    for(unsigned int i=0; i < 9; i++)
        insert_float(&serializer, dcm[i]);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_DCM, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_sensor_2_vehicle_transform_dcm(struct mip_interface* device, float* dcm_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_DCM, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_DCM, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(dcm_out);
        for(unsigned int i=0; i < 9; i++)
            extract_float(&deserializer, &dcm_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_sensor_2_vehicle_transform_dcm(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_DCM, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_sensor_2_vehicle_transform_dcm(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_DCM, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_sensor_2_vehicle_transform_dcm(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR2VEHICLE_TRANSFORM_DCM, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_complementary_filter_command(struct mip_serializer* serializer, const struct mip_3dm_complementary_filter_command* self)
{
    insert_bool(serializer, self->pitch_roll_enable);
    
    insert_bool(serializer, self->heading_enable);
    
    insert_float(serializer, self->pitch_roll_time_constant);
    
    insert_float(serializer, self->heading_time_constant);
    
}
void extract_mip_3dm_complementary_filter_command(struct mip_serializer* serializer, struct mip_3dm_complementary_filter_command* self)
{
    extract_bool(serializer, &self->pitch_roll_enable);
    
    extract_bool(serializer, &self->heading_enable);
    
    extract_float(serializer, &self->pitch_roll_time_constant);
    
    extract_float(serializer, &self->heading_time_constant);
    
}

enum mip_cmd_result mip_3dm_write_complementary_filter(struct mip_interface* device, bool pitch_roll_enable, bool heading_enable, float pitch_roll_time_constant, float heading_time_constant)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_bool(&serializer, pitch_roll_enable);
    
    insert_bool(&serializer, heading_enable);
    
    insert_float(&serializer, pitch_roll_time_constant);
    
    insert_float(&serializer, heading_time_constant);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_LEGACY_COMP_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_complementary_filter(struct mip_interface* device, bool* pitch_roll_enable_out, bool* heading_enable_out, float* pitch_roll_time_constant_out, float* heading_time_constant_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_LEGACY_COMP_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_LEGACY_COMP_FILTER, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        assert(pitch_roll_enable_out);
        extract_bool(&deserializer, pitch_roll_enable_out);
        
        assert(heading_enable_out);
        extract_bool(&deserializer, heading_enable_out);
        
        assert(pitch_roll_time_constant_out);
        extract_float(&deserializer, pitch_roll_time_constant_out);
        
        assert(heading_time_constant_out);
        extract_float(&deserializer, heading_time_constant_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_complementary_filter(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_LEGACY_COMP_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_complementary_filter(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_LEGACY_COMP_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_complementary_filter(struct mip_interface* device)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_LEGACY_COMP_FILTER, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_sensor_range_command(struct mip_serializer* serializer, const struct mip_3dm_sensor_range_command* self)
{
    insert_mip_sensor_range_type(serializer, self->sensor);
    
    insert_u8(serializer, self->setting);
    
}
void extract_mip_3dm_sensor_range_command(struct mip_serializer* serializer, struct mip_3dm_sensor_range_command* self)
{
    extract_mip_sensor_range_type(serializer, &self->sensor);
    
    extract_u8(serializer, &self->setting);
    
}

enum mip_cmd_result mip_3dm_write_sensor_range(struct mip_interface* device, enum mip_sensor_range_type sensor, uint8_t setting)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_WRITE);
    
    insert_mip_sensor_range_type(&serializer, sensor);
    
    insert_u8(&serializer, setting);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR_RANGE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_read_sensor_range(struct mip_interface* device, enum mip_sensor_range_type sensor, uint8_t* setting_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_READ);
    
    insert_mip_sensor_range_type(&serializer, sensor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR_RANGE, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_SENSOR_RANGE, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_mip_sensor_range_type(&deserializer, &sensor);
        
        assert(setting_out);
        extract_u8(&deserializer, setting_out);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}
enum mip_cmd_result mip_3dm_save_sensor_range(struct mip_interface* device, enum mip_sensor_range_type sensor)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_SAVE);
    
    insert_mip_sensor_range_type(&serializer, sensor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR_RANGE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_load_sensor_range(struct mip_interface* device, enum mip_sensor_range_type sensor)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_LOAD);
    
    insert_mip_sensor_range_type(&serializer, sensor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR_RANGE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
enum mip_cmd_result mip_3dm_default_sensor_range(struct mip_interface* device, enum mip_sensor_range_type sensor)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_function_selector(&serializer, MIP_FUNCTION_RESET);
    
    insert_mip_sensor_range_type(&serializer, sensor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    return mip_interface_run_command(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_SENSOR_RANGE, buffer, (uint8_t)mip_serializer_length(&serializer));
}
void insert_mip_3dm_calibrated_sensor_ranges_command(struct mip_serializer* serializer, const struct mip_3dm_calibrated_sensor_ranges_command* self)
{
    insert_mip_sensor_range_type(serializer, self->sensor);
    
}
void extract_mip_3dm_calibrated_sensor_ranges_command(struct mip_serializer* serializer, struct mip_3dm_calibrated_sensor_ranges_command* self)
{
    extract_mip_sensor_range_type(serializer, &self->sensor);
    
}

void insert_mip_3dm_calibrated_sensor_ranges_command_entry(struct mip_serializer* serializer, const struct mip_3dm_calibrated_sensor_ranges_command_entry* self)
{
    insert_u8(serializer, self->setting);
    
    insert_float(serializer, self->range);
    
}
void extract_mip_3dm_calibrated_sensor_ranges_command_entry(struct mip_serializer* serializer, struct mip_3dm_calibrated_sensor_ranges_command_entry* self)
{
    extract_u8(serializer, &self->setting);
    
    extract_float(serializer, &self->range);
    
}

enum mip_cmd_result mip_3dm_calibrated_sensor_ranges(struct mip_interface* device, enum mip_sensor_range_type sensor, uint8_t* num_ranges_out, uint8_t num_ranges_out_max, struct mip_3dm_calibrated_sensor_ranges_command_entry* ranges_out)
{
    struct mip_serializer serializer;
    uint8_t buffer[MIP_FIELD_PAYLOAD_LENGTH_MAX];
    mip_serializer_init_insertion(&serializer, buffer, sizeof(buffer));
    
    insert_mip_sensor_range_type(&serializer, sensor);
    
    assert(mip_serializer_is_ok(&serializer));
    
    uint8_t responseLength = sizeof(buffer);
    enum mip_cmd_result result = mip_interface_run_command_with_response(device, MIP_3DM_CMD_DESC_SET, MIP_CMD_DESC_3DM_CALIBRATED_RANGES, buffer, (uint8_t)mip_serializer_length(&serializer), MIP_REPLY_DESC_3DM_CALIBRATED_RANGES, buffer, &responseLength);
    
    if( result == MIP_ACK_OK )
    {
        struct mip_serializer deserializer;
        mip_serializer_init_insertion(&deserializer, buffer, responseLength);
        
        extract_mip_sensor_range_type(&deserializer, &sensor);
        
        assert(num_ranges_out);
        extract_count(&deserializer, num_ranges_out, num_ranges_out_max);
        
        assert(ranges_out);
        assert(num_ranges_out);
        for(unsigned int i=0; i < *num_ranges_out; i++)
            extract_mip_3dm_calibrated_sensor_ranges_command_entry(&deserializer, &ranges_out[i]);
        
        if( !mip_serializer_is_complete(&deserializer) )
            result = MIP_STATUS_ERROR;
    }
    return result;
}

#ifdef __cplusplus
} // namespace C
} // namespace mip
} // extern "C"
#endif // __cplusplus

