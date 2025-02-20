// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: kv.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_kv_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_kv_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015008 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_kv_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_kv_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_kv_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_kv_2eproto_metadata_getter(int index);
namespace mvccpb {
class Event;
struct EventDefaultTypeInternal;
extern EventDefaultTypeInternal _Event_default_instance_;
class KeyValue;
struct KeyValueDefaultTypeInternal;
extern KeyValueDefaultTypeInternal _KeyValue_default_instance_;
}  // namespace mvccpb
PROTOBUF_NAMESPACE_OPEN
template<> ::mvccpb::Event* Arena::CreateMaybeMessage<::mvccpb::Event>(Arena*);
template<> ::mvccpb::KeyValue* Arena::CreateMaybeMessage<::mvccpb::KeyValue>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mvccpb {

enum Event_EventType : int {
  Event_EventType_PUT = 0,
  Event_EventType_DELETE = 1,
  Event_EventType_Event_EventType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Event_EventType_Event_EventType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Event_EventType_IsValid(int value);
constexpr Event_EventType Event_EventType_EventType_MIN = Event_EventType_PUT;
constexpr Event_EventType Event_EventType_EventType_MAX = Event_EventType_DELETE;
constexpr int Event_EventType_EventType_ARRAYSIZE = Event_EventType_EventType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Event_EventType_descriptor();
template<typename T>
inline const std::string& Event_EventType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Event_EventType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Event_EventType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Event_EventType_descriptor(), enum_t_value);
}
inline bool Event_EventType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Event_EventType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Event_EventType>(
    Event_EventType_descriptor(), name, value);
}
// ===================================================================

class KeyValue PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mvccpb.KeyValue) */ {
 public:
  inline KeyValue() : KeyValue(nullptr) {}
  virtual ~KeyValue();
  explicit constexpr KeyValue(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  KeyValue(const KeyValue& from);
  KeyValue(KeyValue&& from) noexcept
    : KeyValue() {
    *this = ::std::move(from);
  }

  inline KeyValue& operator=(const KeyValue& from) {
    CopyFrom(from);
    return *this;
  }
  inline KeyValue& operator=(KeyValue&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const KeyValue& default_instance() {
    return *internal_default_instance();
  }
  static inline const KeyValue* internal_default_instance() {
    return reinterpret_cast<const KeyValue*>(
               &_KeyValue_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(KeyValue& a, KeyValue& b) {
    a.Swap(&b);
  }
  inline void Swap(KeyValue* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(KeyValue* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline KeyValue* New() const final {
    return CreateMaybeMessage<KeyValue>(nullptr);
  }

  KeyValue* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<KeyValue>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const KeyValue& from);
  void MergeFrom(const KeyValue& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(KeyValue* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mvccpb.KeyValue";
  }
  protected:
  explicit KeyValue(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_kv_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kKeyFieldNumber = 1,
    kValueFieldNumber = 5,
    kCreateRevisionFieldNumber = 2,
    kModRevisionFieldNumber = 3,
    kVersionFieldNumber = 4,
    kLeaseFieldNumber = 6,
  };
  // bytes key = 1;
  void clear_key();
  const std::string& key() const;
  void set_key(const std::string& value);
  void set_key(std::string&& value);
  void set_key(const char* value);
  void set_key(const void* value, size_t size);
  std::string* mutable_key();
  std::string* release_key();
  void set_allocated_key(std::string* key);
  private:
  const std::string& _internal_key() const;
  void _internal_set_key(const std::string& value);
  std::string* _internal_mutable_key();
  public:

  // bytes value = 5;
  void clear_value();
  const std::string& value() const;
  void set_value(const std::string& value);
  void set_value(std::string&& value);
  void set_value(const char* value);
  void set_value(const void* value, size_t size);
  std::string* mutable_value();
  std::string* release_value();
  void set_allocated_value(std::string* value);
  private:
  const std::string& _internal_value() const;
  void _internal_set_value(const std::string& value);
  std::string* _internal_mutable_value();
  public:

  // int64 create_revision = 2;
  void clear_create_revision();
  ::PROTOBUF_NAMESPACE_ID::int64 create_revision() const;
  void set_create_revision(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_create_revision() const;
  void _internal_set_create_revision(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // int64 mod_revision = 3;
  void clear_mod_revision();
  ::PROTOBUF_NAMESPACE_ID::int64 mod_revision() const;
  void set_mod_revision(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_mod_revision() const;
  void _internal_set_mod_revision(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // int64 version = 4;
  void clear_version();
  ::PROTOBUF_NAMESPACE_ID::int64 version() const;
  void set_version(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_version() const;
  void _internal_set_version(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // int64 lease = 6;
  void clear_lease();
  ::PROTOBUF_NAMESPACE_ID::int64 lease() const;
  void set_lease(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_lease() const;
  void _internal_set_lease(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:mvccpb.KeyValue)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr key_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr value_;
  ::PROTOBUF_NAMESPACE_ID::int64 create_revision_;
  ::PROTOBUF_NAMESPACE_ID::int64 mod_revision_;
  ::PROTOBUF_NAMESPACE_ID::int64 version_;
  ::PROTOBUF_NAMESPACE_ID::int64 lease_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_kv_2eproto;
};
// -------------------------------------------------------------------

class Event PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mvccpb.Event) */ {
 public:
  inline Event() : Event(nullptr) {}
  virtual ~Event();
  explicit constexpr Event(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Event(const Event& from);
  Event(Event&& from) noexcept
    : Event() {
    *this = ::std::move(from);
  }

  inline Event& operator=(const Event& from) {
    CopyFrom(from);
    return *this;
  }
  inline Event& operator=(Event&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Event& default_instance() {
    return *internal_default_instance();
  }
  static inline const Event* internal_default_instance() {
    return reinterpret_cast<const Event*>(
               &_Event_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Event& a, Event& b) {
    a.Swap(&b);
  }
  inline void Swap(Event* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Event* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Event* New() const final {
    return CreateMaybeMessage<Event>(nullptr);
  }

  Event* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Event>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Event& from);
  void MergeFrom(const Event& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Event* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mvccpb.Event";
  }
  protected:
  explicit Event(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_kv_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  typedef Event_EventType EventType;
  static constexpr EventType PUT =
    Event_EventType_PUT;
  static constexpr EventType DELETE =
    Event_EventType_DELETE;
  static inline bool EventType_IsValid(int value) {
    return Event_EventType_IsValid(value);
  }
  static constexpr EventType EventType_MIN =
    Event_EventType_EventType_MIN;
  static constexpr EventType EventType_MAX =
    Event_EventType_EventType_MAX;
  static constexpr int EventType_ARRAYSIZE =
    Event_EventType_EventType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  EventType_descriptor() {
    return Event_EventType_descriptor();
  }
  template<typename T>
  static inline const std::string& EventType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, EventType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function EventType_Name.");
    return Event_EventType_Name(enum_t_value);
  }
  static inline bool EventType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      EventType* value) {
    return Event_EventType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kKvFieldNumber = 2,
    kPrevKvFieldNumber = 3,
    kTypeFieldNumber = 1,
  };
  // .mvccpb.KeyValue kv = 2;
  bool has_kv() const;
  private:
  bool _internal_has_kv() const;
  public:
  void clear_kv();
  const ::mvccpb::KeyValue& kv() const;
  ::mvccpb::KeyValue* release_kv();
  ::mvccpb::KeyValue* mutable_kv();
  void set_allocated_kv(::mvccpb::KeyValue* kv);
  private:
  const ::mvccpb::KeyValue& _internal_kv() const;
  ::mvccpb::KeyValue* _internal_mutable_kv();
  public:
  void unsafe_arena_set_allocated_kv(
      ::mvccpb::KeyValue* kv);
  ::mvccpb::KeyValue* unsafe_arena_release_kv();

  // .mvccpb.KeyValue prev_kv = 3;
  bool has_prev_kv() const;
  private:
  bool _internal_has_prev_kv() const;
  public:
  void clear_prev_kv();
  const ::mvccpb::KeyValue& prev_kv() const;
  ::mvccpb::KeyValue* release_prev_kv();
  ::mvccpb::KeyValue* mutable_prev_kv();
  void set_allocated_prev_kv(::mvccpb::KeyValue* prev_kv);
  private:
  const ::mvccpb::KeyValue& _internal_prev_kv() const;
  ::mvccpb::KeyValue* _internal_mutable_prev_kv();
  public:
  void unsafe_arena_set_allocated_prev_kv(
      ::mvccpb::KeyValue* prev_kv);
  ::mvccpb::KeyValue* unsafe_arena_release_prev_kv();

  // .mvccpb.Event.EventType type = 1;
  void clear_type();
  ::mvccpb::Event_EventType type() const;
  void set_type(::mvccpb::Event_EventType value);
  private:
  ::mvccpb::Event_EventType _internal_type() const;
  void _internal_set_type(::mvccpb::Event_EventType value);
  public:

  // @@protoc_insertion_point(class_scope:mvccpb.Event)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::mvccpb::KeyValue* kv_;
  ::mvccpb::KeyValue* prev_kv_;
  int type_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_kv_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// KeyValue

// bytes key = 1;
inline void KeyValue::clear_key() {
  key_.ClearToEmpty();
}
inline const std::string& KeyValue::key() const {
  // @@protoc_insertion_point(field_get:mvccpb.KeyValue.key)
  return _internal_key();
}
inline void KeyValue::set_key(const std::string& value) {
  _internal_set_key(value);
  // @@protoc_insertion_point(field_set:mvccpb.KeyValue.key)
}
inline std::string* KeyValue::mutable_key() {
  // @@protoc_insertion_point(field_mutable:mvccpb.KeyValue.key)
  return _internal_mutable_key();
}
inline const std::string& KeyValue::_internal_key() const {
  return key_.Get();
}
inline void KeyValue::_internal_set_key(const std::string& value) {
  
  key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void KeyValue::set_key(std::string&& value) {
  
  key_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:mvccpb.KeyValue.key)
}
inline void KeyValue::set_key(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:mvccpb.KeyValue.key)
}
inline void KeyValue::set_key(const void* value,
    size_t size) {
  
  key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:mvccpb.KeyValue.key)
}
inline std::string* KeyValue::_internal_mutable_key() {
  
  return key_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* KeyValue::release_key() {
  // @@protoc_insertion_point(field_release:mvccpb.KeyValue.key)
  return key_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void KeyValue::set_allocated_key(std::string* key) {
  if (key != nullptr) {
    
  } else {
    
  }
  key_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), key,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:mvccpb.KeyValue.key)
}

// int64 create_revision = 2;
inline void KeyValue::clear_create_revision() {
  create_revision_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 KeyValue::_internal_create_revision() const {
  return create_revision_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 KeyValue::create_revision() const {
  // @@protoc_insertion_point(field_get:mvccpb.KeyValue.create_revision)
  return _internal_create_revision();
}
inline void KeyValue::_internal_set_create_revision(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  create_revision_ = value;
}
inline void KeyValue::set_create_revision(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_create_revision(value);
  // @@protoc_insertion_point(field_set:mvccpb.KeyValue.create_revision)
}

// int64 mod_revision = 3;
inline void KeyValue::clear_mod_revision() {
  mod_revision_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 KeyValue::_internal_mod_revision() const {
  return mod_revision_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 KeyValue::mod_revision() const {
  // @@protoc_insertion_point(field_get:mvccpb.KeyValue.mod_revision)
  return _internal_mod_revision();
}
inline void KeyValue::_internal_set_mod_revision(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  mod_revision_ = value;
}
inline void KeyValue::set_mod_revision(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_mod_revision(value);
  // @@protoc_insertion_point(field_set:mvccpb.KeyValue.mod_revision)
}

// int64 version = 4;
inline void KeyValue::clear_version() {
  version_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 KeyValue::_internal_version() const {
  return version_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 KeyValue::version() const {
  // @@protoc_insertion_point(field_get:mvccpb.KeyValue.version)
  return _internal_version();
}
inline void KeyValue::_internal_set_version(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  version_ = value;
}
inline void KeyValue::set_version(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_version(value);
  // @@protoc_insertion_point(field_set:mvccpb.KeyValue.version)
}

// bytes value = 5;
inline void KeyValue::clear_value() {
  value_.ClearToEmpty();
}
inline const std::string& KeyValue::value() const {
  // @@protoc_insertion_point(field_get:mvccpb.KeyValue.value)
  return _internal_value();
}
inline void KeyValue::set_value(const std::string& value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:mvccpb.KeyValue.value)
}
inline std::string* KeyValue::mutable_value() {
  // @@protoc_insertion_point(field_mutable:mvccpb.KeyValue.value)
  return _internal_mutable_value();
}
inline const std::string& KeyValue::_internal_value() const {
  return value_.Get();
}
inline void KeyValue::_internal_set_value(const std::string& value) {
  
  value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void KeyValue::set_value(std::string&& value) {
  
  value_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:mvccpb.KeyValue.value)
}
inline void KeyValue::set_value(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:mvccpb.KeyValue.value)
}
inline void KeyValue::set_value(const void* value,
    size_t size) {
  
  value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:mvccpb.KeyValue.value)
}
inline std::string* KeyValue::_internal_mutable_value() {
  
  return value_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* KeyValue::release_value() {
  // @@protoc_insertion_point(field_release:mvccpb.KeyValue.value)
  return value_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void KeyValue::set_allocated_value(std::string* value) {
  if (value != nullptr) {
    
  } else {
    
  }
  value_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:mvccpb.KeyValue.value)
}

// int64 lease = 6;
inline void KeyValue::clear_lease() {
  lease_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 KeyValue::_internal_lease() const {
  return lease_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 KeyValue::lease() const {
  // @@protoc_insertion_point(field_get:mvccpb.KeyValue.lease)
  return _internal_lease();
}
inline void KeyValue::_internal_set_lease(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  lease_ = value;
}
inline void KeyValue::set_lease(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_lease(value);
  // @@protoc_insertion_point(field_set:mvccpb.KeyValue.lease)
}

// -------------------------------------------------------------------

// Event

// .mvccpb.Event.EventType type = 1;
inline void Event::clear_type() {
  type_ = 0;
}
inline ::mvccpb::Event_EventType Event::_internal_type() const {
  return static_cast< ::mvccpb::Event_EventType >(type_);
}
inline ::mvccpb::Event_EventType Event::type() const {
  // @@protoc_insertion_point(field_get:mvccpb.Event.type)
  return _internal_type();
}
inline void Event::_internal_set_type(::mvccpb::Event_EventType value) {
  
  type_ = value;
}
inline void Event::set_type(::mvccpb::Event_EventType value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:mvccpb.Event.type)
}

// .mvccpb.KeyValue kv = 2;
inline bool Event::_internal_has_kv() const {
  return this != internal_default_instance() && kv_ != nullptr;
}
inline bool Event::has_kv() const {
  return _internal_has_kv();
}
inline void Event::clear_kv() {
  if (GetArena() == nullptr && kv_ != nullptr) {
    delete kv_;
  }
  kv_ = nullptr;
}
inline const ::mvccpb::KeyValue& Event::_internal_kv() const {
  const ::mvccpb::KeyValue* p = kv_;
  return p != nullptr ? *p : reinterpret_cast<const ::mvccpb::KeyValue&>(
      ::mvccpb::_KeyValue_default_instance_);
}
inline const ::mvccpb::KeyValue& Event::kv() const {
  // @@protoc_insertion_point(field_get:mvccpb.Event.kv)
  return _internal_kv();
}
inline void Event::unsafe_arena_set_allocated_kv(
    ::mvccpb::KeyValue* kv) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(kv_);
  }
  kv_ = kv;
  if (kv) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:mvccpb.Event.kv)
}
inline ::mvccpb::KeyValue* Event::release_kv() {
  
  ::mvccpb::KeyValue* temp = kv_;
  kv_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::mvccpb::KeyValue* Event::unsafe_arena_release_kv() {
  // @@protoc_insertion_point(field_release:mvccpb.Event.kv)
  
  ::mvccpb::KeyValue* temp = kv_;
  kv_ = nullptr;
  return temp;
}
inline ::mvccpb::KeyValue* Event::_internal_mutable_kv() {
  
  if (kv_ == nullptr) {
    auto* p = CreateMaybeMessage<::mvccpb::KeyValue>(GetArena());
    kv_ = p;
  }
  return kv_;
}
inline ::mvccpb::KeyValue* Event::mutable_kv() {
  // @@protoc_insertion_point(field_mutable:mvccpb.Event.kv)
  return _internal_mutable_kv();
}
inline void Event::set_allocated_kv(::mvccpb::KeyValue* kv) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete kv_;
  }
  if (kv) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(kv);
    if (message_arena != submessage_arena) {
      kv = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, kv, submessage_arena);
    }
    
  } else {
    
  }
  kv_ = kv;
  // @@protoc_insertion_point(field_set_allocated:mvccpb.Event.kv)
}

// .mvccpb.KeyValue prev_kv = 3;
inline bool Event::_internal_has_prev_kv() const {
  return this != internal_default_instance() && prev_kv_ != nullptr;
}
inline bool Event::has_prev_kv() const {
  return _internal_has_prev_kv();
}
inline void Event::clear_prev_kv() {
  if (GetArena() == nullptr && prev_kv_ != nullptr) {
    delete prev_kv_;
  }
  prev_kv_ = nullptr;
}
inline const ::mvccpb::KeyValue& Event::_internal_prev_kv() const {
  const ::mvccpb::KeyValue* p = prev_kv_;
  return p != nullptr ? *p : reinterpret_cast<const ::mvccpb::KeyValue&>(
      ::mvccpb::_KeyValue_default_instance_);
}
inline const ::mvccpb::KeyValue& Event::prev_kv() const {
  // @@protoc_insertion_point(field_get:mvccpb.Event.prev_kv)
  return _internal_prev_kv();
}
inline void Event::unsafe_arena_set_allocated_prev_kv(
    ::mvccpb::KeyValue* prev_kv) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(prev_kv_);
  }
  prev_kv_ = prev_kv;
  if (prev_kv) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:mvccpb.Event.prev_kv)
}
inline ::mvccpb::KeyValue* Event::release_prev_kv() {
  
  ::mvccpb::KeyValue* temp = prev_kv_;
  prev_kv_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::mvccpb::KeyValue* Event::unsafe_arena_release_prev_kv() {
  // @@protoc_insertion_point(field_release:mvccpb.Event.prev_kv)
  
  ::mvccpb::KeyValue* temp = prev_kv_;
  prev_kv_ = nullptr;
  return temp;
}
inline ::mvccpb::KeyValue* Event::_internal_mutable_prev_kv() {
  
  if (prev_kv_ == nullptr) {
    auto* p = CreateMaybeMessage<::mvccpb::KeyValue>(GetArena());
    prev_kv_ = p;
  }
  return prev_kv_;
}
inline ::mvccpb::KeyValue* Event::mutable_prev_kv() {
  // @@protoc_insertion_point(field_mutable:mvccpb.Event.prev_kv)
  return _internal_mutable_prev_kv();
}
inline void Event::set_allocated_prev_kv(::mvccpb::KeyValue* prev_kv) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete prev_kv_;
  }
  if (prev_kv) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(prev_kv);
    if (message_arena != submessage_arena) {
      prev_kv = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, prev_kv, submessage_arena);
    }
    
  } else {
    
  }
  prev_kv_ = prev_kv;
  // @@protoc_insertion_point(field_set_allocated:mvccpb.Event.prev_kv)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace mvccpb

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::mvccpb::Event_EventType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::mvccpb::Event_EventType>() {
  return ::mvccpb::Event_EventType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_kv_2eproto
