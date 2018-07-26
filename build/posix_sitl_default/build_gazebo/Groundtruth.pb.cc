// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Groundtruth.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Groundtruth.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace gps_msgs {
namespace msgs {

namespace {

const ::google::protobuf::Descriptor* Groundtruth_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Groundtruth_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Groundtruth_2eproto() {
  protobuf_AddDesc_Groundtruth_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Groundtruth.proto");
  GOOGLE_CHECK(file != NULL);
  Groundtruth_descriptor_ = file->message_type(0);
  static const int Groundtruth_offsets_[11] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, latitude_rad_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, longitude_rad_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, altitude_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, velocity_east_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, velocity_north_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, velocity_up_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, attitude_q_w_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, attitude_q_x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, attitude_q_y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, attitude_q_z_),
  };
  Groundtruth_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Groundtruth_descriptor_,
      Groundtruth::default_instance_,
      Groundtruth_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Groundtruth, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Groundtruth));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Groundtruth_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Groundtruth_descriptor_, &Groundtruth::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Groundtruth_2eproto() {
  delete Groundtruth::default_instance_;
  delete Groundtruth_reflection_;
}

void protobuf_AddDesc_Groundtruth_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021Groundtruth.proto\022\rgps_msgs.msgs\"\366\001\n\013G"
    "roundtruth\022\014\n\004time\030\001 \002(\001\022\024\n\014latitude_rad"
    "\030\002 \002(\001\022\025\n\rlongitude_rad\030\003 \002(\001\022\020\n\010altitud"
    "e\030\004 \002(\001\022\025\n\rvelocity_east\030\005 \001(\001\022\026\n\016veloci"
    "ty_north\030\006 \001(\001\022\023\n\013velocity_up\030\007 \001(\001\022\024\n\014a"
    "ttitude_q_w\030\010 \001(\001\022\024\n\014attitude_q_x\030\t \001(\001\022"
    "\024\n\014attitude_q_y\030\n \001(\001\022\024\n\014attitude_q_z\030\013 "
    "\001(\001", 283);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Groundtruth.proto", &protobuf_RegisterTypes);
  Groundtruth::default_instance_ = new Groundtruth();
  Groundtruth::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Groundtruth_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Groundtruth_2eproto {
  StaticDescriptorInitializer_Groundtruth_2eproto() {
    protobuf_AddDesc_Groundtruth_2eproto();
  }
} static_descriptor_initializer_Groundtruth_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Groundtruth::kTimeFieldNumber;
const int Groundtruth::kLatitudeRadFieldNumber;
const int Groundtruth::kLongitudeRadFieldNumber;
const int Groundtruth::kAltitudeFieldNumber;
const int Groundtruth::kVelocityEastFieldNumber;
const int Groundtruth::kVelocityNorthFieldNumber;
const int Groundtruth::kVelocityUpFieldNumber;
const int Groundtruth::kAttitudeQWFieldNumber;
const int Groundtruth::kAttitudeQXFieldNumber;
const int Groundtruth::kAttitudeQYFieldNumber;
const int Groundtruth::kAttitudeQZFieldNumber;
#endif  // !_MSC_VER

Groundtruth::Groundtruth()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gps_msgs.msgs.Groundtruth)
}

void Groundtruth::InitAsDefaultInstance() {
}

Groundtruth::Groundtruth(const Groundtruth& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gps_msgs.msgs.Groundtruth)
}

void Groundtruth::SharedCtor() {
  _cached_size_ = 0;
  time_ = 0;
  latitude_rad_ = 0;
  longitude_rad_ = 0;
  altitude_ = 0;
  velocity_east_ = 0;
  velocity_north_ = 0;
  velocity_up_ = 0;
  attitude_q_w_ = 0;
  attitude_q_x_ = 0;
  attitude_q_y_ = 0;
  attitude_q_z_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Groundtruth::~Groundtruth() {
  // @@protoc_insertion_point(destructor:gps_msgs.msgs.Groundtruth)
  SharedDtor();
}

void Groundtruth::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Groundtruth::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Groundtruth::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Groundtruth_descriptor_;
}

const Groundtruth& Groundtruth::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Groundtruth_2eproto();
  return *default_instance_;
}

Groundtruth* Groundtruth::default_instance_ = NULL;

Groundtruth* Groundtruth::New() const {
  return new Groundtruth;
}

void Groundtruth::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Groundtruth*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(time_, attitude_q_w_);
  }
  ZR_(attitude_q_x_, attitude_q_z_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Groundtruth::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gps_msgs.msgs.Groundtruth)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required double time = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &time_)));
          set_has_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(17)) goto parse_latitude_rad;
        break;
      }

      // required double latitude_rad = 2;
      case 2: {
        if (tag == 17) {
         parse_latitude_rad:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &latitude_rad_)));
          set_has_latitude_rad();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(25)) goto parse_longitude_rad;
        break;
      }

      // required double longitude_rad = 3;
      case 3: {
        if (tag == 25) {
         parse_longitude_rad:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &longitude_rad_)));
          set_has_longitude_rad();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(33)) goto parse_altitude;
        break;
      }

      // required double altitude = 4;
      case 4: {
        if (tag == 33) {
         parse_altitude:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &altitude_)));
          set_has_altitude();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(41)) goto parse_velocity_east;
        break;
      }

      // optional double velocity_east = 5;
      case 5: {
        if (tag == 41) {
         parse_velocity_east:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &velocity_east_)));
          set_has_velocity_east();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(49)) goto parse_velocity_north;
        break;
      }

      // optional double velocity_north = 6;
      case 6: {
        if (tag == 49) {
         parse_velocity_north:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &velocity_north_)));
          set_has_velocity_north();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(57)) goto parse_velocity_up;
        break;
      }

      // optional double velocity_up = 7;
      case 7: {
        if (tag == 57) {
         parse_velocity_up:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &velocity_up_)));
          set_has_velocity_up();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(65)) goto parse_attitude_q_w;
        break;
      }

      // optional double attitude_q_w = 8;
      case 8: {
        if (tag == 65) {
         parse_attitude_q_w:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &attitude_q_w_)));
          set_has_attitude_q_w();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(73)) goto parse_attitude_q_x;
        break;
      }

      // optional double attitude_q_x = 9;
      case 9: {
        if (tag == 73) {
         parse_attitude_q_x:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &attitude_q_x_)));
          set_has_attitude_q_x();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(81)) goto parse_attitude_q_y;
        break;
      }

      // optional double attitude_q_y = 10;
      case 10: {
        if (tag == 81) {
         parse_attitude_q_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &attitude_q_y_)));
          set_has_attitude_q_y();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(89)) goto parse_attitude_q_z;
        break;
      }

      // optional double attitude_q_z = 11;
      case 11: {
        if (tag == 89) {
         parse_attitude_q_z:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &attitude_q_z_)));
          set_has_attitude_q_z();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gps_msgs.msgs.Groundtruth)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gps_msgs.msgs.Groundtruth)
  return false;
#undef DO_
}

void Groundtruth::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gps_msgs.msgs.Groundtruth)
  // required double time = 1;
  if (has_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->time(), output);
  }

  // required double latitude_rad = 2;
  if (has_latitude_rad()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->latitude_rad(), output);
  }

  // required double longitude_rad = 3;
  if (has_longitude_rad()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->longitude_rad(), output);
  }

  // required double altitude = 4;
  if (has_altitude()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->altitude(), output);
  }

  // optional double velocity_east = 5;
  if (has_velocity_east()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(5, this->velocity_east(), output);
  }

  // optional double velocity_north = 6;
  if (has_velocity_north()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(6, this->velocity_north(), output);
  }

  // optional double velocity_up = 7;
  if (has_velocity_up()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(7, this->velocity_up(), output);
  }

  // optional double attitude_q_w = 8;
  if (has_attitude_q_w()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(8, this->attitude_q_w(), output);
  }

  // optional double attitude_q_x = 9;
  if (has_attitude_q_x()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(9, this->attitude_q_x(), output);
  }

  // optional double attitude_q_y = 10;
  if (has_attitude_q_y()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(10, this->attitude_q_y(), output);
  }

  // optional double attitude_q_z = 11;
  if (has_attitude_q_z()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(11, this->attitude_q_z(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gps_msgs.msgs.Groundtruth)
}

::google::protobuf::uint8* Groundtruth::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gps_msgs.msgs.Groundtruth)
  // required double time = 1;
  if (has_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->time(), target);
  }

  // required double latitude_rad = 2;
  if (has_latitude_rad()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->latitude_rad(), target);
  }

  // required double longitude_rad = 3;
  if (has_longitude_rad()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->longitude_rad(), target);
  }

  // required double altitude = 4;
  if (has_altitude()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->altitude(), target);
  }

  // optional double velocity_east = 5;
  if (has_velocity_east()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, this->velocity_east(), target);
  }

  // optional double velocity_north = 6;
  if (has_velocity_north()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(6, this->velocity_north(), target);
  }

  // optional double velocity_up = 7;
  if (has_velocity_up()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(7, this->velocity_up(), target);
  }

  // optional double attitude_q_w = 8;
  if (has_attitude_q_w()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(8, this->attitude_q_w(), target);
  }

  // optional double attitude_q_x = 9;
  if (has_attitude_q_x()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(9, this->attitude_q_x(), target);
  }

  // optional double attitude_q_y = 10;
  if (has_attitude_q_y()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, this->attitude_q_y(), target);
  }

  // optional double attitude_q_z = 11;
  if (has_attitude_q_z()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(11, this->attitude_q_z(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gps_msgs.msgs.Groundtruth)
  return target;
}

int Groundtruth::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required double time = 1;
    if (has_time()) {
      total_size += 1 + 8;
    }

    // required double latitude_rad = 2;
    if (has_latitude_rad()) {
      total_size += 1 + 8;
    }

    // required double longitude_rad = 3;
    if (has_longitude_rad()) {
      total_size += 1 + 8;
    }

    // required double altitude = 4;
    if (has_altitude()) {
      total_size += 1 + 8;
    }

    // optional double velocity_east = 5;
    if (has_velocity_east()) {
      total_size += 1 + 8;
    }

    // optional double velocity_north = 6;
    if (has_velocity_north()) {
      total_size += 1 + 8;
    }

    // optional double velocity_up = 7;
    if (has_velocity_up()) {
      total_size += 1 + 8;
    }

    // optional double attitude_q_w = 8;
    if (has_attitude_q_w()) {
      total_size += 1 + 8;
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional double attitude_q_x = 9;
    if (has_attitude_q_x()) {
      total_size += 1 + 8;
    }

    // optional double attitude_q_y = 10;
    if (has_attitude_q_y()) {
      total_size += 1 + 8;
    }

    // optional double attitude_q_z = 11;
    if (has_attitude_q_z()) {
      total_size += 1 + 8;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Groundtruth::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Groundtruth* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Groundtruth*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Groundtruth::MergeFrom(const Groundtruth& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_time()) {
      set_time(from.time());
    }
    if (from.has_latitude_rad()) {
      set_latitude_rad(from.latitude_rad());
    }
    if (from.has_longitude_rad()) {
      set_longitude_rad(from.longitude_rad());
    }
    if (from.has_altitude()) {
      set_altitude(from.altitude());
    }
    if (from.has_velocity_east()) {
      set_velocity_east(from.velocity_east());
    }
    if (from.has_velocity_north()) {
      set_velocity_north(from.velocity_north());
    }
    if (from.has_velocity_up()) {
      set_velocity_up(from.velocity_up());
    }
    if (from.has_attitude_q_w()) {
      set_attitude_q_w(from.attitude_q_w());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_attitude_q_x()) {
      set_attitude_q_x(from.attitude_q_x());
    }
    if (from.has_attitude_q_y()) {
      set_attitude_q_y(from.attitude_q_y());
    }
    if (from.has_attitude_q_z()) {
      set_attitude_q_z(from.attitude_q_z());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Groundtruth::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Groundtruth::CopyFrom(const Groundtruth& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Groundtruth::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void Groundtruth::Swap(Groundtruth* other) {
  if (other != this) {
    std::swap(time_, other->time_);
    std::swap(latitude_rad_, other->latitude_rad_);
    std::swap(longitude_rad_, other->longitude_rad_);
    std::swap(altitude_, other->altitude_);
    std::swap(velocity_east_, other->velocity_east_);
    std::swap(velocity_north_, other->velocity_north_);
    std::swap(velocity_up_, other->velocity_up_);
    std::swap(attitude_q_w_, other->attitude_q_w_);
    std::swap(attitude_q_x_, other->attitude_q_x_);
    std::swap(attitude_q_y_, other->attitude_q_y_);
    std::swap(attitude_q_z_, other->attitude_q_z_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Groundtruth::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Groundtruth_descriptor_;
  metadata.reflection = Groundtruth_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace msgs
}  // namespace gps_msgs

// @@protoc_insertion_point(global_scope)
