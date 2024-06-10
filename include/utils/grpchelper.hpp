/*
 * Copyright (C) 2024 Renesas Electronics Corporation.
 * Copyright (C) 2024 EPAM Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GRPCHELPER_HPP_
#define GRPCHELPER_HPP_

#include <grpcpp/security/credentials.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/support/server_interceptor.h>

#include <aos/common/crypto.hpp>
#include <aos/common/cryptoutils.hpp>
#include <aos/iam/certhandler.hpp>

namespace aos::common::utils {

/**
 * Get server credentials for mTLS.
 *
 * @param certInfo certificate information.
 * @param rootCertPath path to the root certificate.
 * @param certLoader certificate loader.
 * @param cryptoProvider crypto provider.
 * @return server credentials.
 */
std::shared_ptr<grpc::ServerCredentials> GetMTLSServerCredentials(const aos::iam::certhandler::CertInfo& certInfo,
    const aos::String& rootCertPath, aos::cryptoutils::CertLoader& certLoader,
    aos::crypto::x509::ProviderItf& cryptoProvider);

/**
 * Get server credentials for TLS.
 *
 * @param certInfo certificate information.
 * @param certLoader certificate loader.
 * @param cryptoProvider crypto provider.
 * @return server credentials.
 */
std::shared_ptr<grpc::ServerCredentials> GetTLSServerCredentials(const aos::iam::certhandler::CertInfo& certInfo,
    aos::cryptoutils::CertLoader& certLoader, aos::crypto::x509::ProviderItf& cryptoProvider);

/**
 * Get channel credentials for TLS.
 *
 * @param certInfo certificate information.
 * @param rootCertPath path to the root certificate.
 * @param certLoader certificate loader.
 * @param cryptoProvider crypto provider.
 * @return channel credentials.
 */
std::shared_ptr<grpc::ChannelCredentials> GetTLSChannelCredentials(const aos::iam::certhandler::CertInfo& certInfo,
    const aos::String& rootCertPath, aos::cryptoutils::CertLoaderItf& certLoader,
    aos::crypto::x509::ProviderItf& cryptoProvider);

/**
 * Creates URL server interceptor factory.
 *
 * @param serverURL server URL.
 * @return std::unique_ptr<grpc::experimental::ServerInterceptorFactoryInterface>
 */
std::unique_ptr<grpc::experimental::ServerInterceptorFactoryInterface> CreateServerURLInterceptorFactory(
    const std::string& serverURL);

} // namespace aos::common::utils

#endif
