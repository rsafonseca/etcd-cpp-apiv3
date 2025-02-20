// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: kv.proto

#include "kv.pb.h"

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

PROTOBUF_PRAGMA_INIT_SEG
namespace mvccpb {
constexpr KeyValue::KeyValue(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : key_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , value_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , create_revision_(PROTOBUF_LONGLONG(0))
  , mod_revision_(PROTOBUF_LONGLONG(0))
  , version_(PROTOBUF_LONGLONG(0))
  , lease_(PROTOBUF_LONGLONG(0)){}
struct KeyValueDefaultTypeInternal {
  constexpr KeyValueDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~KeyValueDefaultTypeInternal() {}
  union {
    KeyValue _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT KeyValueDefaultTypeInternal _KeyValue_default_instance_;
constexpr Event::Event(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : kv_(nullptr)
  , prev_kv_(nullptr)
  , type_(0)
{}
struct EventDefaultTypeInternal {
  constexpr EventDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~EventDefaultTypeInternal() {}
  union {
    Event _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT EventDefaultTypeInternal _Event_default_instance_;
}  // namespace mvccpb
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_kv_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_kv_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_kv_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_kv_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, key_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, create_revision_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, mod_revision_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, version_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, value_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, lease_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::mvccpb::Event, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mvccpb::Event, type_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::Event, kv_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::Event, prev_kv_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::mvccpb::KeyValue)},
  { 11, -1, sizeof(::mvccpb::Event)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mvccpb::_KeyValue_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mvccpb::_Event_default_instance_),
};

const char descriptor_table_protodef_kv_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\010kv.proto\022\006mvccpb\"u\n\010KeyValue\022\013\n\003key\030\001 "
  "\001(\014\022\027\n\017create_revision\030\002 \001(\003\022\024\n\014mod_revi"
  "sion\030\003 \001(\003\022\017\n\007version\030\004 \001(\003\022\r\n\005value\030\005 \001"
  "(\014\022\r\n\005lease\030\006 \001(\003\"\221\001\n\005Event\022%\n\004type\030\001 \001("
  "\0162\027.mvccpb.Event.EventType\022\034\n\002kv\030\002 \001(\0132\020"
  ".mvccpb.KeyValue\022!\n\007prev_kv\030\003 \001(\0132\020.mvcc"
  "pb.KeyValue\" \n\tEventType\022\007\n\003PUT\020\000\022\n\n\006DEL"
  "ETE\020\001b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_kv_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_kv_2eproto = {
  false, false, 293, descriptor_table_protodef_kv_2eproto, "kv.proto", 
  &descriptor_table_kv_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_kv_2eproto::offsets,
  file_level_metadata_kv_2eproto, file_level_enum_descriptors_kv_2eproto, file_level_service_descriptors_kv_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_kv_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_kv_2eproto);
  return descriptor_table_kv_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_kv_2eproto(&descriptor_table_kv_2eproto);
namespace mvccpb {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Event_EventType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_kv_2eproto);
  return file_level_enum_descriptors_kv_2eproto[0];
}
bool Event_EventType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr Event_EventType Event::PUT;
constexpr Event_EventType Event::DELETE;
constexpr Event_EventType Event::EventType_MIN;
constexpr Event_EventType Event::EventType_MAX;
constexpr int Event::EventType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

class KeyValue::_Internal {
 public:
};

KeyValue::KeyValue(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:mvccpb.KeyValue)
}
KeyValue::KeyValue(const KeyValue& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_key().empty()) {
    key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_key(), 
      GetArena());
  }
  value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_value().empty()) {
    value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_value(), 
      GetArena());
  }
  ::memcpy(&create_revision_, &from.create_revision_,
    static_cast<size_t>(reinterpret_cast<char*>(&lease_) -
    reinterpret_cast<char*>(&create_revision_)) + sizeof(lease_));
  // @@protoc_insertion_point(copy_constructor:mvccpb.KeyValue)
}

void KeyValue::SharedCtor() {
key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&create_revision_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&lease_) -
    reinterpret_cast<char*>(&create_revision_)) + sizeof(lease_));
}

KeyValue::~KeyValue() {
  // @@protoc_insertion_point(destructor:mvccpb.KeyValue)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void KeyValue::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  key_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  value_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void KeyValue::ArenaDtor(void* object) {
  KeyValue* _this = reinterpret_cast< KeyValue* >(object);
  (void)_this;
}
void KeyValue::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void KeyValue::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void KeyValue::Clear() {
// @@protoc_insertion_point(message_clear_start:mvccpb.KeyValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  key_.ClearToEmpty();
  value_.ClearToEmpty();
  ::memset(&create_revision_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&lease_) -
      reinterpret_cast<char*>(&create_revision_)) + sizeof(lease_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* KeyValue::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes key = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_key();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 create_revision = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          create_revision_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 mod_revision = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          mod_revision_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 version = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          version_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes value = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_value();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 lease = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          lease_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* KeyValue::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mvccpb.KeyValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes key = 1;
  if (this->key().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_key(), target);
  }

  // int64 create_revision = 2;
  if (this->create_revision() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(2, this->_internal_create_revision(), target);
  }

  // int64 mod_revision = 3;
  if (this->mod_revision() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(3, this->_internal_mod_revision(), target);
  }

  // int64 version = 4;
  if (this->version() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(4, this->_internal_version(), target);
  }

  // bytes value = 5;
  if (this->value().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        5, this->_internal_value(), target);
  }

  // int64 lease = 6;
  if (this->lease() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(6, this->_internal_lease(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mvccpb.KeyValue)
  return target;
}

size_t KeyValue::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mvccpb.KeyValue)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes key = 1;
  if (this->key().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_key());
  }

  // bytes value = 5;
  if (this->value().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_value());
  }

  // int64 create_revision = 2;
  if (this->create_revision() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_create_revision());
  }

  // int64 mod_revision = 3;
  if (this->mod_revision() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_mod_revision());
  }

  // int64 version = 4;
  if (this->version() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_version());
  }

  // int64 lease = 6;
  if (this->lease() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_lease());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void KeyValue::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mvccpb.KeyValue)
  GOOGLE_DCHECK_NE(&from, this);
  const KeyValue* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<KeyValue>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mvccpb.KeyValue)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mvccpb.KeyValue)
    MergeFrom(*source);
  }
}

void KeyValue::MergeFrom(const KeyValue& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mvccpb.KeyValue)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.key().size() > 0) {
    _internal_set_key(from._internal_key());
  }
  if (from.value().size() > 0) {
    _internal_set_value(from._internal_value());
  }
  if (from.create_revision() != 0) {
    _internal_set_create_revision(from._internal_create_revision());
  }
  if (from.mod_revision() != 0) {
    _internal_set_mod_revision(from._internal_mod_revision());
  }
  if (from.version() != 0) {
    _internal_set_version(from._internal_version());
  }
  if (from.lease() != 0) {
    _internal_set_lease(from._internal_lease());
  }
}

void KeyValue::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mvccpb.KeyValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void KeyValue::CopyFrom(const KeyValue& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mvccpb.KeyValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool KeyValue::IsInitialized() const {
  return true;
}

void KeyValue::InternalSwap(KeyValue* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  key_.Swap(&other->key_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  value_.Swap(&other->value_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(KeyValue, lease_)
      + sizeof(KeyValue::lease_)
      - PROTOBUF_FIELD_OFFSET(KeyValue, create_revision_)>(
          reinterpret_cast<char*>(&create_revision_),
          reinterpret_cast<char*>(&other->create_revision_));
}

::PROTOBUF_NAMESPACE_ID::Metadata KeyValue::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class Event::_Internal {
 public:
  static const ::mvccpb::KeyValue& kv(const Event* msg);
  static const ::mvccpb::KeyValue& prev_kv(const Event* msg);
};

const ::mvccpb::KeyValue&
Event::_Internal::kv(const Event* msg) {
  return *msg->kv_;
}
const ::mvccpb::KeyValue&
Event::_Internal::prev_kv(const Event* msg) {
  return *msg->prev_kv_;
}
Event::Event(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:mvccpb.Event)
}
Event::Event(const Event& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_kv()) {
    kv_ = new ::mvccpb::KeyValue(*from.kv_);
  } else {
    kv_ = nullptr;
  }
  if (from._internal_has_prev_kv()) {
    prev_kv_ = new ::mvccpb::KeyValue(*from.prev_kv_);
  } else {
    prev_kv_ = nullptr;
  }
  type_ = from.type_;
  // @@protoc_insertion_point(copy_constructor:mvccpb.Event)
}

void Event::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&kv_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&type_) -
    reinterpret_cast<char*>(&kv_)) + sizeof(type_));
}

Event::~Event() {
  // @@protoc_insertion_point(destructor:mvccpb.Event)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Event::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete kv_;
  if (this != internal_default_instance()) delete prev_kv_;
}

void Event::ArenaDtor(void* object) {
  Event* _this = reinterpret_cast< Event* >(object);
  (void)_this;
}
void Event::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Event::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Event::Clear() {
// @@protoc_insertion_point(message_clear_start:mvccpb.Event)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && kv_ != nullptr) {
    delete kv_;
  }
  kv_ = nullptr;
  if (GetArena() == nullptr && prev_kv_ != nullptr) {
    delete prev_kv_;
  }
  prev_kv_ = nullptr;
  type_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Event::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .mvccpb.Event.EventType type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_type(static_cast<::mvccpb::Event_EventType>(val));
        } else goto handle_unusual;
        continue;
      // .mvccpb.KeyValue kv = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_kv(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .mvccpb.KeyValue prev_kv = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_prev_kv(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Event::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mvccpb.Event)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .mvccpb.Event.EventType type = 1;
  if (this->type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_type(), target);
  }

  // .mvccpb.KeyValue kv = 2;
  if (this->has_kv()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::kv(this), target, stream);
  }

  // .mvccpb.KeyValue prev_kv = 3;
  if (this->has_prev_kv()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        3, _Internal::prev_kv(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mvccpb.Event)
  return target;
}

size_t Event::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mvccpb.Event)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .mvccpb.KeyValue kv = 2;
  if (this->has_kv()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *kv_);
  }

  // .mvccpb.KeyValue prev_kv = 3;
  if (this->has_prev_kv()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *prev_kv_);
  }

  // .mvccpb.Event.EventType type = 1;
  if (this->type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_type());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Event::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mvccpb.Event)
  GOOGLE_DCHECK_NE(&from, this);
  const Event* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Event>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mvccpb.Event)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mvccpb.Event)
    MergeFrom(*source);
  }
}

void Event::MergeFrom(const Event& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mvccpb.Event)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_kv()) {
    _internal_mutable_kv()->::mvccpb::KeyValue::MergeFrom(from._internal_kv());
  }
  if (from.has_prev_kv()) {
    _internal_mutable_prev_kv()->::mvccpb::KeyValue::MergeFrom(from._internal_prev_kv());
  }
  if (from.type() != 0) {
    _internal_set_type(from._internal_type());
  }
}

void Event::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mvccpb.Event)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Event::CopyFrom(const Event& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mvccpb.Event)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Event::IsInitialized() const {
  return true;
}

void Event::InternalSwap(Event* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Event, type_)
      + sizeof(Event::type_)
      - PROTOBUF_FIELD_OFFSET(Event, kv_)>(
          reinterpret_cast<char*>(&kv_),
          reinterpret_cast<char*>(&other->kv_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Event::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace mvccpb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mvccpb::KeyValue* Arena::CreateMaybeMessage< ::mvccpb::KeyValue >(Arena* arena) {
  return Arena::CreateMessageInternal< ::mvccpb::KeyValue >(arena);
}
template<> PROTOBUF_NOINLINE ::mvccpb::Event* Arena::CreateMaybeMessage< ::mvccpb::Event >(Arena* arena) {
  return Arena::CreateMessageInternal< ::mvccpb::Event >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
