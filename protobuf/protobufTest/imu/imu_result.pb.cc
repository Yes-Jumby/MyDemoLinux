// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: imu_result.proto

#include "imu_result.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace protodata {
class imu_resultDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<imu_result> _instance;
} _imu_result_default_instance_;
}  // namespace protodata
static void InitDefaultsscc_info_imu_result_imu_5fresult_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protodata::_imu_result_default_instance_;
    new (ptr) ::protodata::imu_result();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protodata::imu_result::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_imu_result_imu_5fresult_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_imu_result_imu_5fresult_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_imu_5fresult_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_imu_5fresult_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_imu_5fresult_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_imu_5fresult_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r11_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r12_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r13_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r21_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r22_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r23_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r31_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r32_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, r33_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, dx_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, dy_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, dz_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, time_stamp_),
  PROTOBUF_FIELD_OFFSET(::protodata::imu_result, odometer_count_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::protodata::imu_result)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protodata::_imu_result_default_instance_),
};

const char descriptor_table_protodef_imu_5fresult_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020imu_result.proto\022\tprotodata\"\321\001\n\nimu_re"
  "sult\022\013\n\003R11\030\001 \001(\001\022\013\n\003R12\030\002 \001(\001\022\013\n\003R13\030\003 "
  "\001(\001\022\013\n\003R21\030\004 \001(\001\022\013\n\003R22\030\005 \001(\001\022\013\n\003R23\030\006 \001"
  "(\001\022\013\n\003R31\030\007 \001(\001\022\013\n\003R32\030\010 \001(\001\022\013\n\003R33\030\t \001("
  "\001\022\n\n\002dx\030\n \001(\001\022\n\n\002dy\030\013 \001(\001\022\n\n\002dz\030\014 \001(\001\022\022\n"
  "\ntime_stamp\030\r \001(\004\022\026\n\016odometer_count\030\016 \001("
  "\005b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_imu_5fresult_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_imu_5fresult_2eproto_sccs[1] = {
  &scc_info_imu_result_imu_5fresult_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_imu_5fresult_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_imu_5fresult_2eproto = {
  false, false, descriptor_table_protodef_imu_5fresult_2eproto, "imu_result.proto", 249,
  &descriptor_table_imu_5fresult_2eproto_once, descriptor_table_imu_5fresult_2eproto_sccs, descriptor_table_imu_5fresult_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_imu_5fresult_2eproto::offsets,
  file_level_metadata_imu_5fresult_2eproto, 1, file_level_enum_descriptors_imu_5fresult_2eproto, file_level_service_descriptors_imu_5fresult_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_imu_5fresult_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_imu_5fresult_2eproto)), true);
namespace protodata {

// ===================================================================

void imu_result::InitAsDefaultInstance() {
}
class imu_result::_Internal {
 public:
};

imu_result::imu_result(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:protodata.imu_result)
}
imu_result::imu_result(const imu_result& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&r11_, &from.r11_,
    static_cast<size_t>(reinterpret_cast<char*>(&odometer_count_) -
    reinterpret_cast<char*>(&r11_)) + sizeof(odometer_count_));
  // @@protoc_insertion_point(copy_constructor:protodata.imu_result)
}

void imu_result::SharedCtor() {
  ::memset(&r11_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&odometer_count_) -
      reinterpret_cast<char*>(&r11_)) + sizeof(odometer_count_));
}

imu_result::~imu_result() {
  // @@protoc_insertion_point(destructor:protodata.imu_result)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void imu_result::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void imu_result::ArenaDtor(void* object) {
  imu_result* _this = reinterpret_cast< imu_result* >(object);
  (void)_this;
}
void imu_result::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void imu_result::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const imu_result& imu_result::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_imu_result_imu_5fresult_2eproto.base);
  return *internal_default_instance();
}


void imu_result::Clear() {
// @@protoc_insertion_point(message_clear_start:protodata.imu_result)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&r11_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&odometer_count_) -
      reinterpret_cast<char*>(&r11_)) + sizeof(odometer_count_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* imu_result::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // double R11 = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 9)) {
          r11_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double R12 = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 17)) {
          r12_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double R13 = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 25)) {
          r13_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double R21 = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 33)) {
          r21_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double R22 = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 41)) {
          r22_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double R23 = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 49)) {
          r23_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double R31 = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 57)) {
          r31_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double R32 = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 65)) {
          r32_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double R33 = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 73)) {
          r33_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double dx = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 81)) {
          dx_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double dy = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 89)) {
          dy_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double dz = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 97)) {
          dz_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // uint64 time_stamp = 13;
      case 13:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 104)) {
          time_stamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 odometer_count = 14;
      case 14:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 112)) {
          odometer_count_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* imu_result::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protodata.imu_result)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double R11 = 1;
  if (!(this->r11() <= 0 && this->r11() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(1, this->_internal_r11(), target);
  }

  // double R12 = 2;
  if (!(this->r12() <= 0 && this->r12() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(2, this->_internal_r12(), target);
  }

  // double R13 = 3;
  if (!(this->r13() <= 0 && this->r13() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(3, this->_internal_r13(), target);
  }

  // double R21 = 4;
  if (!(this->r21() <= 0 && this->r21() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(4, this->_internal_r21(), target);
  }

  // double R22 = 5;
  if (!(this->r22() <= 0 && this->r22() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(5, this->_internal_r22(), target);
  }

  // double R23 = 6;
  if (!(this->r23() <= 0 && this->r23() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(6, this->_internal_r23(), target);
  }

  // double R31 = 7;
  if (!(this->r31() <= 0 && this->r31() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(7, this->_internal_r31(), target);
  }

  // double R32 = 8;
  if (!(this->r32() <= 0 && this->r32() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(8, this->_internal_r32(), target);
  }

  // double R33 = 9;
  if (!(this->r33() <= 0 && this->r33() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(9, this->_internal_r33(), target);
  }

  // double dx = 10;
  if (!(this->dx() <= 0 && this->dx() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(10, this->_internal_dx(), target);
  }

  // double dy = 11;
  if (!(this->dy() <= 0 && this->dy() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(11, this->_internal_dy(), target);
  }

  // double dz = 12;
  if (!(this->dz() <= 0 && this->dz() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(12, this->_internal_dz(), target);
  }

  // uint64 time_stamp = 13;
  if (this->time_stamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(13, this->_internal_time_stamp(), target);
  }

  // int32 odometer_count = 14;
  if (this->odometer_count() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(14, this->_internal_odometer_count(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protodata.imu_result)
  return target;
}

size_t imu_result::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protodata.imu_result)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // double R11 = 1;
  if (!(this->r11() <= 0 && this->r11() >= 0)) {
    total_size += 1 + 8;
  }

  // double R12 = 2;
  if (!(this->r12() <= 0 && this->r12() >= 0)) {
    total_size += 1 + 8;
  }

  // double R13 = 3;
  if (!(this->r13() <= 0 && this->r13() >= 0)) {
    total_size += 1 + 8;
  }

  // double R21 = 4;
  if (!(this->r21() <= 0 && this->r21() >= 0)) {
    total_size += 1 + 8;
  }

  // double R22 = 5;
  if (!(this->r22() <= 0 && this->r22() >= 0)) {
    total_size += 1 + 8;
  }

  // double R23 = 6;
  if (!(this->r23() <= 0 && this->r23() >= 0)) {
    total_size += 1 + 8;
  }

  // double R31 = 7;
  if (!(this->r31() <= 0 && this->r31() >= 0)) {
    total_size += 1 + 8;
  }

  // double R32 = 8;
  if (!(this->r32() <= 0 && this->r32() >= 0)) {
    total_size += 1 + 8;
  }

  // double R33 = 9;
  if (!(this->r33() <= 0 && this->r33() >= 0)) {
    total_size += 1 + 8;
  }

  // double dx = 10;
  if (!(this->dx() <= 0 && this->dx() >= 0)) {
    total_size += 1 + 8;
  }

  // double dy = 11;
  if (!(this->dy() <= 0 && this->dy() >= 0)) {
    total_size += 1 + 8;
  }

  // double dz = 12;
  if (!(this->dz() <= 0 && this->dz() >= 0)) {
    total_size += 1 + 8;
  }

  // uint64 time_stamp = 13;
  if (this->time_stamp() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_time_stamp());
  }

  // int32 odometer_count = 14;
  if (this->odometer_count() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_odometer_count());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void imu_result::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protodata.imu_result)
  GOOGLE_DCHECK_NE(&from, this);
  const imu_result* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<imu_result>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protodata.imu_result)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protodata.imu_result)
    MergeFrom(*source);
  }
}

void imu_result::MergeFrom(const imu_result& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protodata.imu_result)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.r11() <= 0 && from.r11() >= 0)) {
    _internal_set_r11(from._internal_r11());
  }
  if (!(from.r12() <= 0 && from.r12() >= 0)) {
    _internal_set_r12(from._internal_r12());
  }
  if (!(from.r13() <= 0 && from.r13() >= 0)) {
    _internal_set_r13(from._internal_r13());
  }
  if (!(from.r21() <= 0 && from.r21() >= 0)) {
    _internal_set_r21(from._internal_r21());
  }
  if (!(from.r22() <= 0 && from.r22() >= 0)) {
    _internal_set_r22(from._internal_r22());
  }
  if (!(from.r23() <= 0 && from.r23() >= 0)) {
    _internal_set_r23(from._internal_r23());
  }
  if (!(from.r31() <= 0 && from.r31() >= 0)) {
    _internal_set_r31(from._internal_r31());
  }
  if (!(from.r32() <= 0 && from.r32() >= 0)) {
    _internal_set_r32(from._internal_r32());
  }
  if (!(from.r33() <= 0 && from.r33() >= 0)) {
    _internal_set_r33(from._internal_r33());
  }
  if (!(from.dx() <= 0 && from.dx() >= 0)) {
    _internal_set_dx(from._internal_dx());
  }
  if (!(from.dy() <= 0 && from.dy() >= 0)) {
    _internal_set_dy(from._internal_dy());
  }
  if (!(from.dz() <= 0 && from.dz() >= 0)) {
    _internal_set_dz(from._internal_dz());
  }
  if (from.time_stamp() != 0) {
    _internal_set_time_stamp(from._internal_time_stamp());
  }
  if (from.odometer_count() != 0) {
    _internal_set_odometer_count(from._internal_odometer_count());
  }
}

void imu_result::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protodata.imu_result)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void imu_result::CopyFrom(const imu_result& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protodata.imu_result)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool imu_result::IsInitialized() const {
  return true;
}

void imu_result::InternalSwap(imu_result* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(imu_result, odometer_count_)
      + sizeof(imu_result::odometer_count_)
      - PROTOBUF_FIELD_OFFSET(imu_result, r11_)>(
          reinterpret_cast<char*>(&r11_),
          reinterpret_cast<char*>(&other->r11_));
}

::PROTOBUF_NAMESPACE_ID::Metadata imu_result::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protodata
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protodata::imu_result* Arena::CreateMaybeMessage< ::protodata::imu_result >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protodata::imu_result >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
