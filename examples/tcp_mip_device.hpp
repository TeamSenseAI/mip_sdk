#pragma once

#include <mscl/mip/mip_device.hpp>

#include <socket/tcp.hpp>

#include <string>


extern mscl::Timestamp getCurrentTimestamp();


class TcpMipDevice : public mscl::MipDeviceInterface
{
public:
    TcpMipDevice(const std::string& hostname, uint16_t port);

    bool update() final;
    bool sendToDevice(const uint8_t* data, size_t length) final;

private:
    mscl::TcpSocket mSocket;
    uint8_t mParseBuffer[1024];
};
