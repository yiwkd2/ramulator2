#include <filesystem>
#include <iostream>
#include <fstream>

#include "frontend/frontend.h"
#include "base/exception.h"

namespace Ramulator {


class USIM : public IFrontEnd, public Implementation {
  RAMULATOR_REGISTER_IMPLEMENTATION(IFrontEnd, USIM, "USIM", "USIM frontend.")

  public:
    void init() override { };
    void tick() override { };

    bool receive_external_requests(Ramulator::Request& req) override {
      return m_memory_system->send(req);
    }

    bool can_accept(unsigned channel_id, int req_type) {
      return m_memory_system->can_accept(channel_id, req_type);
    }

  private:
    bool is_finished() override { return true; };
};

}        // namespace Ramulator
