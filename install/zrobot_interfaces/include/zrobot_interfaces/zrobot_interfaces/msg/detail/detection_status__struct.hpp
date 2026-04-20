// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/msg/detection_status.hpp"


#ifndef ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__STRUCT_HPP_
#define ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__zrobot_interfaces__msg__DetectionStatus __attribute__((deprecated))
#else
# define DEPRECATED__zrobot_interfaces__msg__DetectionStatus __declspec(deprecated)
#endif

namespace zrobot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionStatus_
{
  using Type = DetectionStatus_<ContainerAllocator>;

  explicit DetectionStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_object = "";
      this->target_found = false;
      this->zone = "";
      this->target_count = 0l;
      this->confidence = 0.0f;
      this->inference_time_ms = 0.0f;
      this->fps = 0l;
      this->frame_width = 0l;
      this->frame_height = 0l;
      this->target_center_x = 0.0f;
    }
  }

  explicit DetectionStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_object(_alloc),
    zone(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_object = "";
      this->target_found = false;
      this->zone = "";
      this->target_count = 0l;
      this->confidence = 0.0f;
      this->inference_time_ms = 0.0f;
      this->fps = 0l;
      this->frame_width = 0l;
      this->frame_height = 0l;
      this->target_center_x = 0.0f;
    }
  }

  // field types and members
  using _target_object_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_object_type target_object;
  using _target_found_type =
    bool;
  _target_found_type target_found;
  using _zone_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_type zone;
  using _target_count_type =
    int32_t;
  _target_count_type target_count;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _inference_time_ms_type =
    float;
  _inference_time_ms_type inference_time_ms;
  using _fps_type =
    int32_t;
  _fps_type fps;
  using _frame_width_type =
    int32_t;
  _frame_width_type frame_width;
  using _frame_height_type =
    int32_t;
  _frame_height_type frame_height;
  using _target_center_x_type =
    float;
  _target_center_x_type target_center_x;

  // setters for named parameter idiom
  Type & set__target_object(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target_object = _arg;
    return *this;
  }
  Type & set__target_found(
    const bool & _arg)
  {
    this->target_found = _arg;
    return *this;
  }
  Type & set__zone(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone = _arg;
    return *this;
  }
  Type & set__target_count(
    const int32_t & _arg)
  {
    this->target_count = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__inference_time_ms(
    const float & _arg)
  {
    this->inference_time_ms = _arg;
    return *this;
  }
  Type & set__fps(
    const int32_t & _arg)
  {
    this->fps = _arg;
    return *this;
  }
  Type & set__frame_width(
    const int32_t & _arg)
  {
    this->frame_width = _arg;
    return *this;
  }
  Type & set__frame_height(
    const int32_t & _arg)
  {
    this->frame_height = _arg;
    return *this;
  }
  Type & set__target_center_x(
    const float & _arg)
  {
    this->target_center_x = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zrobot_interfaces__msg__DetectionStatus
    std::shared_ptr<zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zrobot_interfaces__msg__DetectionStatus
    std::shared_ptr<zrobot_interfaces::msg::DetectionStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionStatus_ & other) const
  {
    if (this->target_object != other.target_object) {
      return false;
    }
    if (this->target_found != other.target_found) {
      return false;
    }
    if (this->zone != other.zone) {
      return false;
    }
    if (this->target_count != other.target_count) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->inference_time_ms != other.inference_time_ms) {
      return false;
    }
    if (this->fps != other.fps) {
      return false;
    }
    if (this->frame_width != other.frame_width) {
      return false;
    }
    if (this->frame_height != other.frame_height) {
      return false;
    }
    if (this->target_center_x != other.target_center_x) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionStatus_

// alias to use template instance with default allocator
using DetectionStatus =
  zrobot_interfaces::msg::DetectionStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace zrobot_interfaces

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__STRUCT_HPP_
