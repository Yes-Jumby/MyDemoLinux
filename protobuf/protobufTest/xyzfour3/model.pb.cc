// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: model.proto

#include "model.pb.h"

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
namespace hello {
class MyDataDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<MyData> _instance;
} _MyData_default_instance_;
}  // namespace hello
static void InitDefaultsscc_info_MyData_model_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::hello::_MyData_default_instance_;
    new (ptr) ::hello::MyData();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::hello::MyData::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_MyData_model_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_MyData_model_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_model_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_model_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_model_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_model_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::hello::MyData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::hello::MyData, timestamp_),
  PROTOBUF_FIELD_OFFSET(::hello::MyData, x_),
  PROTOBUF_FIELD_OFFSET(::hello::MyData, y_),
  PROTOBUF_FIELD_OFFSET(::hello::MyData, z_),
  PROTOBUF_FIELD_OFFSET(::hello::MyData, qx_),
  PROTOBUF_FIELD_OFFSET(::hello::MyData, qy_),
  PROTOBUF_FIELD_OFFSET(::hello::MyData, qz_),
  PROTOBUF_FIELD_OFFSET(::hello::MyData, qw_),
  PROTOBUF_FIELD_OFFSET(::hello::MyData, username_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::hello::MyData)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::hello::_MyData_default_instance_),
};

const char descriptor_table_protodef_model_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013model.proto\022\005hello\"~\n\006MyData\022\021\n\ttimest"
  "amp\030\001 \001(\004\022\t\n\001x\030\002 \001(\001\022\t\n\001y\030\003 \001(\001\022\t\n\001z\030\004 \001"
  "(\001\022\n\n\002qx\030\005 \001(\001\022\n\n\002qy\030\006 \001(\001\022\n\n\002qz\030\007 \001(\001\022\n"
  "\n\002qw\030\010 \001(\001\022\020\n\010username\030\t \001(\tb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_model_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_model_2eproto_sccs[1] = {
  &scc_info_MyData_model_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_model_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_model_2eproto = {
  false, false, descriptor_table_protodef_model_2eproto, "model.proto", 156,
  &descriptor_table_model_2eproto_once, descriptor_table_model_2eproto_sccs, descriptor_table_model_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_model_2eproto::offsets,
  file_level_metadata_model_2eproto, 1, file_level_enum_descriptors_model_2eproto, file_level_service_descriptors_model_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_model_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_model_2eproto)), true);
namespace hello {

// ===================================================================

void MyData::InitAsDefaultInstance() {
}
class MyData::_Internal {
 public:
};

MyData::MyData(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:hello.MyData)
}
MyData::MyData(const MyData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  username_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_username().empty()) {
    username_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_username(),
      GetArena());
  }
  ::memcpy(&timestamp_, &from.timestamp_,
    static_cast<size_t>(reinterpret_cast<char*>(&qw_) -
    reinterpret_cast<char*>(&timestamp_)) + sizeof(qw_));
  // @@protoc_insertion_point(copy_constructor:hello.MyData)
}

void MyData::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_MyData_model_2eproto.base);
  username_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&timestamp_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&qw_) -
      reinterpret_cast<char*>(&timestamp_)) + sizeof(qw_));
}

MyData::~MyData() {
  // @@protoc_insertion_point(destructor:hello.MyData)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void MyData::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  username_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void MyData::ArenaDtor(void* object) {
  MyData* _this = reinterpret_cast< MyData* >(object);
  (void)_this;
}
void MyData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void MyData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const MyData& MyData::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_MyData_model_2eproto.base);
  return *internal_default_instance();
}


void MyData::Clear() {
// @@protoc_insertion_point(message_clear_start:hello.MyData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  username_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&timestamp_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&qw_) -
      reinterpret_cast<char*>(&timestamp_)) + sizeof(qw_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MyData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint64 timestamp = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double x = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 17)) {
          x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double y = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 25)) {
          y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double z = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 33)) {
          z_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double qx = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 41)) {
          qx_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double qy = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 49)) {
          qy_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double qz = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 57)) {
          qz_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double qw = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 65)) {
          qw_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // string username = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 74)) {
          auto str = _internal_mutable_username();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "hello.MyData.username"));
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

::PROTOBUF_NAMESPACE_ID::uint8* MyData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:hello.MyData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 timestamp = 1;
  if (this->timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_timestamp(), target);
  }

  // double x = 2;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(2, this->_internal_x(), target);
  }

  // double y = 3;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(3, this->_internal_y(), target);
  }

  // double z = 4;
  if (!(this->z() <= 0 && this->z() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(4, this->_internal_z(), target);
  }

  // double qx = 5;
  if (!(this->qx() <= 0 && this->qx() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(5, this->_internal_qx(), target);
  }

  // double qy = 6;
  if (!(this->qy() <= 0 && this->qy() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(6, this->_internal_qy(), target);
  }

  // double qz = 7;
  if (!(this->qz() <= 0 && this->qz() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(7, this->_internal_qz(), target);
  }

  // double qw = 8;
  if (!(this->qw() <= 0 && this->qw() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(8, this->_internal_qw(), target);
  }

  // string username = 9;
  if (this->username().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_username().data(), static_cast<int>(this->_internal_username().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "hello.MyData.username");
    target = stream->WriteStringMaybeAliased(
        9, this->_internal_username(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:hello.MyData)
  return target;
}

size_t MyData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:hello.MyData)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string username = 9;
  if (this->username().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_username());
  }

  // uint64 timestamp = 1;
  if (this->timestamp() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_timestamp());
  }

  // double x = 2;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    total_size += 1 + 8;
  }

  // double y = 3;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    total_size += 1 + 8;
  }

  // double z = 4;
  if (!(this->z() <= 0 && this->z() >= 0)) {
    total_size += 1 + 8;
  }

  // double qx = 5;
  if (!(this->qx() <= 0 && this->qx() >= 0)) {
    total_size += 1 + 8;
  }

  // double qy = 6;
  if (!(this->qy() <= 0 && this->qy() >= 0)) {
    total_size += 1 + 8;
  }

  // double qz = 7;
  if (!(this->qz() <= 0 && this->qz() >= 0)) {
    total_size += 1 + 8;
  }

  // double qw = 8;
  if (!(this->qw() <= 0 && this->qw() >= 0)) {
    total_size += 1 + 8;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MyData::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:hello.MyData)
  GOOGLE_DCHECK_NE(&from, this);
  const MyData* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<MyData>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:hello.MyData)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:hello.MyData)
    MergeFrom(*source);
  }
}

void MyData::MergeFrom(const MyData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:hello.MyData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.username().size() > 0) {
    _internal_set_username(from._internal_username());
  }
  if (from.timestamp() != 0) {
    _internal_set_timestamp(from._internal_timestamp());
  }
  if (!(from.x() <= 0 && from.x() >= 0)) {
    _internal_set_x(from._internal_x());
  }
  if (!(from.y() <= 0 && from.y() >= 0)) {
    _internal_set_y(from._internal_y());
  }
  if (!(from.z() <= 0 && from.z() >= 0)) {
    _internal_set_z(from._internal_z());
  }
  if (!(from.qx() <= 0 && from.qx() >= 0)) {
    _internal_set_qx(from._internal_qx());
  }
  if (!(from.qy() <= 0 && from.qy() >= 0)) {
    _internal_set_qy(from._internal_qy());
  }
  if (!(from.qz() <= 0 && from.qz() >= 0)) {
    _internal_set_qz(from._internal_qz());
  }
  if (!(from.qw() <= 0 && from.qw() >= 0)) {
    _internal_set_qw(from._internal_qw());
  }
}

void MyData::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:hello.MyData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MyData::CopyFrom(const MyData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:hello.MyData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MyData::IsInitialized() const {
  return true;
}

void MyData::InternalSwap(MyData* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  username_.Swap(&other->username_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MyData, qw_)
      + sizeof(MyData::qw_)
      - PROTOBUF_FIELD_OFFSET(MyData, timestamp_)>(
          reinterpret_cast<char*>(&timestamp_),
          reinterpret_cast<char*>(&other->timestamp_));
}

::PROTOBUF_NAMESPACE_ID::Metadata MyData::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace hello
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::hello::MyData* Arena::CreateMaybeMessage< ::hello::MyData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::hello::MyData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
