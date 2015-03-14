#pragma once

#include "transactions/OperationFrame.h"

// Copyright 2014 Stellar Development Foundation and contributors. Licensed
// under the ISC License. See the COPYING file at the top-level directory of
// this distribution or at http://opensource.org/licenses/ISC

namespace stellar
{
class ChangeTrustOpFrame : public OperationFrame
{
    ChangeTrust::ChangeTrustResult&
    innerResult()
    {
        return mResult.tr().changeTrustResult();
    }
    ChangeTrustOp const& mChangeTrust;

  public:
    ChangeTrustOpFrame(Operation const& op, OperationResult& res,
                       TransactionFrame& parentTx);

    bool doApply(LedgerDelta& delta, LedgerMaster& ledgerMaster);
    bool doCheckValid(Application& app);
};

namespace ChangeTrust
{
inline ChangeTrust::ChangeTrustResultCode
getInnerCode(OperationResult const& res)
{
    return res.tr().changeTrustResult().code();
}
}
}