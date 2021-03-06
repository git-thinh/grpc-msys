// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: hellostreamingworld.proto
// Original file comments:
// Copyright 2015 gRPC authors.
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
//
#ifndef GRPC_hellostreamingworld_2eproto__INCLUDED
#define GRPC_hellostreamingworld_2eproto__INCLUDED

#include "hellostreamingworld.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace hellostreamingworld {

// The greeting service definition.
class MultiGreeter final {
 public:
  static constexpr char const* service_full_name() {
    return "hellostreamingworld.MultiGreeter";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Sends multiple greetings
    std::unique_ptr< ::grpc::ClientReaderInterface< ::hellostreamingworld::HelloReply>> sayHello(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::hellostreamingworld::HelloReply>>(sayHelloRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::hellostreamingworld::HelloReply>> AsyncsayHello(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::hellostreamingworld::HelloReply>>(AsyncsayHelloRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::hellostreamingworld::HelloReply>> PrepareAsyncsayHello(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::hellostreamingworld::HelloReply>>(PrepareAsyncsayHelloRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientReaderInterface< ::hellostreamingworld::HelloReply>* sayHelloRaw(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::hellostreamingworld::HelloReply>* AsyncsayHelloRaw(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::hellostreamingworld::HelloReply>* PrepareAsyncsayHelloRaw(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReader< ::hellostreamingworld::HelloReply>> sayHello(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::hellostreamingworld::HelloReply>>(sayHelloRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::hellostreamingworld::HelloReply>> AsyncsayHello(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::hellostreamingworld::HelloReply>>(AsyncsayHelloRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::hellostreamingworld::HelloReply>> PrepareAsyncsayHello(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::hellostreamingworld::HelloReply>>(PrepareAsyncsayHelloRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientReader< ::hellostreamingworld::HelloReply>* sayHelloRaw(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request) override;
    ::grpc::ClientAsyncReader< ::hellostreamingworld::HelloReply>* AsyncsayHelloRaw(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::hellostreamingworld::HelloReply>* PrepareAsyncsayHelloRaw(::grpc::ClientContext* context, const ::hellostreamingworld::HelloRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::RpcMethod rpcmethod_sayHello_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Sends multiple greetings
    virtual ::grpc::Status sayHello(::grpc::ServerContext* context, const ::hellostreamingworld::HelloRequest* request, ::grpc::ServerWriter< ::hellostreamingworld::HelloReply>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_sayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_sayHello() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_sayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sayHello(::grpc::ServerContext* context, const ::hellostreamingworld::HelloRequest* request, ::grpc::ServerWriter< ::hellostreamingworld::HelloReply>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsayHello(::grpc::ServerContext* context, ::hellostreamingworld::HelloRequest* request, ::grpc::ServerAsyncWriter< ::hellostreamingworld::HelloReply>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_sayHello<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_sayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_sayHello() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_sayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sayHello(::grpc::ServerContext* context, const ::hellostreamingworld::HelloRequest* request, ::grpc::ServerWriter< ::hellostreamingworld::HelloReply>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  typedef Service StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_sayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithSplitStreamingMethod_sayHello() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::SplitServerStreamingHandler< ::hellostreamingworld::HelloRequest, ::hellostreamingworld::HelloReply>(std::bind(&WithSplitStreamingMethod_sayHello<BaseClass>::StreamedsayHello, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithSplitStreamingMethod_sayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status sayHello(::grpc::ServerContext* context, const ::hellostreamingworld::HelloRequest* request, ::grpc::ServerWriter< ::hellostreamingworld::HelloReply>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedsayHello(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::hellostreamingworld::HelloRequest,::hellostreamingworld::HelloReply>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_sayHello<Service > SplitStreamedService;
  typedef WithSplitStreamingMethod_sayHello<Service > StreamedService;
};

}  // namespace hellostreamingworld


#endif  // GRPC_hellostreamingworld_2eproto__INCLUDED
