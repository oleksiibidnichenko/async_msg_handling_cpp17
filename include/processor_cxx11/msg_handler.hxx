#pragma once

#include <memory>
#include <boost/asio.hpp>

#include "base_message.hxx"
#include "common_msg_handler.hxx"

namespace app {

class MessageHandler final: public CommonMessageHandler {
public:
    explicit MessageHandler(boost::asio::io_context &io_context);
    ~MessageHandler() = default;

    MessageHandler(const MessageHandler&) = delete;
    MessageHandler& operator=(const MessageHandler&) = delete;

    MessageHandler(MessageHandler&&) = delete;
    MessageHandler& operator=(MessageHandler&&) = delete;

protected:
    void cbReceive(const std::vector<std::byte>& data) override;

    void onConnTerm() noexcept override;

private:
    using Container = std::vector<std::byte>;

    void HandleMessage(std::unique_ptr<msg::BaseMsg> msg);

    size_t mCtr;
};

}  // namespace app
