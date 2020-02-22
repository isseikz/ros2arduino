
#ifndef _MY_MSGS_MPU9250_HPP_
#define _MY_MSGS_MPU9250_HPP_

#include "../topic.hpp"
#include "../std_msgs/Header.hpp"

namespace my_msgs {

class ImuMPU9250 : public ros2::Topic<ImuMPU9250>
{
public:
    std_msgs::Header header;
    float linear_acceleration[3];
    float angular_velocity[3];
    float magnetic_field[3];

  ImuMPU9250():
    Topic("my_msgs::msg::dds_::ImuMPU9250_", "ImuMPU9250", MY_MSGS_MPU9250_ID),
    header()
  { 
    memset(linear_acceleration, 0, sizeof(linear_acceleration));
    memset(angular_velocity, 0, sizeof(angular_velocity));
    memset(magnetic_field, 0, sizeof(magnetic_field));
  }

  bool serialize(void* msg_buf, const ImuMPU9250* topic)
  {
    ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
    (void) header.serialize(writer, &topic->header);
    (void) ucdr_serialize_array_float(writer, topic->linear_acceleration, 3);
    (void) ucdr_serialize_array_float(writer, topic->angular_velocity, 3);
    (void) ucdr_serialize_array_float(writer, topic->magnetic_field, 3);

    return !writer->error;
  }

  bool deserialize(void* msg_buf, ImuMPU9250* topic)
  {
    ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
    (void) header.deserialize(reader, &topic->header);
    (void) ucdr_deserialize_array_float(reader, topic->linear_acceleration, 3);
    (void) ucdr_deserialize_array_float(reader, topic->angular_velocity, 3);
    (void) ucdr_deserialize_array_float(reader, topic->magnetic_field, 3);

    return !reader->error;
  }

  uint32_t size_of_topic(const ImuMPU9250* topic, uint32_t size)
  {
    uint32_t previousSize = size;

    size += header.size_of_topic(&topic->header, size);
    size += ucdr_alignment(size, 4) + ((3) * 4);
    size += ucdr_alignment(size, 4) + ((3) * 4);
    size += ucdr_alignment(size, 4) + ((3) * 4);

    return size - previousSize;
  }

};

} // namespace my_msgs


#endif // _MY_MSGS_MPU9250_HPP_
