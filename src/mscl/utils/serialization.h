#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "../types.h"

#ifdef __cplusplus
#include <type_traits>

namespace mscl {
namespace C {
extern "C" {
#endif // __cplusplus


////////////////////////////////////////////////////////////////////////////////
///@defgroup Serialization Functions for reading and writing to byte buffers.
///
///@{

struct mip_serializer
{
    uint8_t* buffer;
    size_t   buffer_size;
    size_t   offset;
};

void mip_serializer_init_insertion(struct mip_serializer* serializer, uint8_t* buffer, size_t buffer_size);
void mip_serializer_init_extraction(struct mip_serializer* serializer, const uint8_t* buffer, size_t buffer_size);
bool mip_serializer_ok(const struct mip_serializer* serializer);


void insert_bool(struct mip_serializer* serializer, bool value);
void insert_char(struct mip_serializer* serializer, char value);

void insert_u8 (struct mip_serializer* serializer, uint8_t  value);
void insert_u16(struct mip_serializer* serializer, uint16_t value);
void insert_u32(struct mip_serializer* serializer, uint32_t value);
void insert_u64(struct mip_serializer* serializer, uint64_t value);

void insert_s8 (struct mip_serializer* serializer, int8_t  value);
void insert_s16(struct mip_serializer* serializer, int16_t value);
void insert_s32(struct mip_serializer* serializer, int32_t value);
void insert_s64(struct mip_serializer* serializer, int64_t value);

void insert_float (struct mip_serializer* serializer, float  value);
void insert_double(struct mip_serializer* serializer, double value);


void extract_bool(struct mip_serializer* serializer, bool* value);
void extract_char(struct mip_serializer* serializer, char* value);

void extract_u8 (struct mip_serializer* serializer, uint8_t* value);
void extract_u16(struct mip_serializer* serializer, uint16_t* value);
void extract_u32(struct mip_serializer* serializer, uint32_t* value);
void extract_u64(struct mip_serializer* serializer, uint64_t* value);

void extract_s8 (struct mip_serializer* serializer, int8_t* value);
void extract_s16(struct mip_serializer* serializer, int16_t* value);
void extract_s32(struct mip_serializer* serializer, int32_t* value);
void extract_s64(struct mip_serializer* serializer, int64_t* value);

void extract_float (struct mip_serializer* serializer, float* value);
void extract_double(struct mip_serializer* serializer, double* value);

void extract_count(struct mip_serializer* serializer, uint8_t* count_out, uint8_t max_count);

///@}
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} // extern "C"
} // namespace C

class MipSerializer : public C::mip_serializer
{
public:
    MipSerializer(uint8_t* buffer, size_t size) { C::mip_serializer_init_insertion(this, buffer, size); }
    MipSerializer(const uint8_t* buffer, size_t size) { C::mip_serializer_init_extraction(this, const_cast<uint8_t*>(buffer), size); }

    operator const void*() const { return C::mip_serializer_ok(this) ? this : nullptr; }
    bool operator!() const { return C::mip_serializer_ok(this); }
};


void insert(MipSerializer& serializer, bool value)     { return C::insert_bool  (&serializer, value); }
void insert(MipSerializer& serializer, char value)     { return C::insert_char  (&serializer, value); }
void insert(MipSerializer& serializer, uint8_t  value) { return C::insert_u8    (&serializer, value); }
void insert(MipSerializer& serializer, uint16_t value) { return C::insert_u16   (&serializer, value); }
void insert(MipSerializer& serializer, uint32_t value) { return C::insert_u32   (&serializer, value); }
void insert(MipSerializer& serializer, uint64_t value) { return C::insert_u64   (&serializer, value); }
void insert(MipSerializer& serializer, int8_t  value)  { return C::insert_s8    (&serializer, value); }
void insert(MipSerializer& serializer, int16_t value)  { return C::insert_s16   (&serializer, value); }
void insert(MipSerializer& serializer, int32_t value)  { return C::insert_s32   (&serializer, value); }
void insert(MipSerializer& serializer, int64_t value)  { return C::insert_s64   (&serializer, value); }
void insert(MipSerializer& serializer, float  value)   { return C::insert_float (&serializer, value); }
void insert(MipSerializer& serializer, double value)   { return C::insert_double(&serializer, value); }

template<typename Enum>
typename std::enable_if< std::is_enum<Enum>::value, void>::type
/*void*/ insert(MipSerializer& serializer, Enum value) { return insert(serializer, static_cast< typename std::underlying_type<Enum>::type >(value) ); }


void extract(MipSerializer& serializer, bool& value)     { return C::extract_bool  (&serializer, &value); }
void extract(MipSerializer& serializer, char& value)     { return C::extract_char  (&serializer, &value); }
void extract(MipSerializer& serializer, uint8_t&  value) { return C::extract_u8    (&serializer, &value); }
void extract(MipSerializer& serializer, uint16_t& value) { return C::extract_u16   (&serializer, &value); }
void extract(MipSerializer& serializer, uint32_t& value) { return C::extract_u32   (&serializer, &value); }
void extract(MipSerializer& serializer, uint64_t& value) { return C::extract_u64   (&serializer, &value); }
void extract(MipSerializer& serializer, int8_t&  value)  { return C::extract_s8    (&serializer, &value); }
void extract(MipSerializer& serializer, int16_t& value)  { return C::extract_s16   (&serializer, &value); }
void extract(MipSerializer& serializer, int32_t& value)  { return C::extract_s32   (&serializer, &value); }
void extract(MipSerializer& serializer, int64_t& value)  { return C::extract_s64   (&serializer, &value); }
void extract(MipSerializer& serializer, float&  value)   { return C::extract_float (&serializer, &value); }
void extract(MipSerializer& serializer, double& value)   { return C::extract_double(&serializer, &value); }

template<typename Enum>
typename std::enable_if< std::is_enum<Enum>::value, void>::type
/*void*/ extract(MipSerializer& serializer, Enum value) { return insert(serializer, static_cast< typename std::underlying_type<Enum>::type >(value) ); }


template<typename T>
bool extract(T& value_out, const uint8_t* buffer, size_t bufferSize /*, size_t offset=0 */)
{
    MipSerializer serializer(buffer, bufferSize);
    extract(serializer, value_out);
    return !!serializer;
}

} // namespace mscl
#endif // __cplusplus
