// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


/*! 
 * @file Time.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */
#ifndef _BUILTIN_INTERFACES_TIME_HPP_
#define _BUILTIN_INTERFACES_TIME_HPP_


#include "../topic.hpp"


namespace builtin_interfaces {


class Time : public ros2::Topic<Time>
{
public: 
  int32_t sec;
  uint32_t nanosec;

  Time():
    Topic("builtin_interfaces::msg::dds_::Time_", "Time"),
    sec(0), nanosec(0)
  {
  }

  bool serialize(void* msg_buf, const Time* topic)
  {
    ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
    (void) ucdr_serialize_int32_t(writer, topic->sec);
    (void) ucdr_serialize_uint32_t(writer, topic->nanosec);

    return !writer->error;
  }

  bool deserialize(void* msg_buf, Time* topic)
  {
    ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
    (void) ucdr_deserialize_int32_t(reader, &topic->sec);
    (void) ucdr_deserialize_uint32_t(reader, &topic->nanosec);

    return !reader->error;
  }

  uint32_t size_of_topic(const Time* topic, uint32_t size)
  {
    (void)(topic);

    uint32_t previousSize = size;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;

    return size - previousSize;
  }

};

} // namespace builtin_interfaces


#endif // _BUILTIN_INTERFACES_TIME_HPP_
