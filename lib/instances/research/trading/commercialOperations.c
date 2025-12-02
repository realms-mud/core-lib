//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

///////////////////////////////////////////////////////////////////////////////
//public void BasicTrading()
//{
//    addResearchElement("/lib/instances/research/trading/market-analysis.c");
//    addChild("/lib/instances/research/trading/market-analysis.c",
//        "/lib/instances/research/trading/basicCommerce.c");
//
//    addResearchElement("/lib/instances/research/trading/cargo-management.c");
//    addChild("/lib/instances/research/trading/cargo-management.c",
//        "/lib/instances/research/trading/basicCommerce.c");
//
//    addResearchElement("/lib/instances/research/trading/route-planning.c");
//    addChild("/lib/instances/research/trading/route-planning.c",
//        "/lib/instances/research/trading/market-analysis.c");
//}
//
///////////////////////////////////////////////////////////////////////////////
//public void AdvancedTrading()
//{
//    addResearchElement("/lib/instances/research/trading/advanced-market-analysis.c");
//    addChild("/lib/instances/research/trading/advanced-market-analysis.c",
//        "/lib/instances/research/trading/route-planning.c");
//
//    addResearchElement("/lib/instances/research/trading/contract-negotiation.c");
//    addChild("/lib/instances/research/trading/contract-negotiation.c",
//        "/lib/instances/research/trading/advanced-market-analysis.c");
//
//    addResearchElement("/lib/instances/research/trading/bulk-trading.c");
//    addChild("/lib/instances/research/trading/bulk-trading.c",
//        "/lib/instances/research/trading/cargo-management.c");
//
//    addResearchElement("/lib/instances/research/trading/commodity-speculation.c");
//    addChild("/lib/instances/research/trading/commodity-speculation.c",
//        "/lib/instances/research/trading/contract-negotiation.c");
//}
//
///////////////////////////////////////////////////////////////////////////////
//public void VehicleOperations()
//{
//    addResearchElement("/lib/instances/research/trading/vehicle-crew-management.c");
//    addChild("/lib/instances/research/trading/vehicle-crew-management.c",
//        "/lib/instances/research/trading/basicCommerce.c");
//
//    addResearchElement("/lib/instances/research/trading/vehicle-maintenance.c");
//    addChild("/lib/instances/research/trading/vehicle-maintenance.c",
//        "/lib/instances/research/trading/vehicle-crew-management.c");
//
//    addResearchElement("/lib/instances/research/trading/fleet-management.c");
//    addChild("/lib/instances/research/trading/fleet-management.c",
//        "/lib/instances/research/trading/vehicle-maintenance.c");
//
//    addResearchElement("/lib/instances/research/trading/advanced-logistics.c");
//    addChild("/lib/instances/research/trading/advanced-logistics.c",
//        "/lib/instances/research/trading/fleet-management.c");
//}
//
///////////////////////////////////////////////////////////////////////////////
//public void FinancialOperations()
//{
//    addResearchElement("/lib/instances/research/trading/banking-operations.c");
//    addChild("/lib/instances/research/trading/banking-operations.c",
//        "/lib/instances/research/trading/contract-negotiation.c");
//
//    addResearchElement("/lib/instances/research/trading/credit-management.c");
//    addChild("/lib/instances/research/trading/credit-management.c",
//        "/lib/instances/research/trading/banking-operations.c");
//
//    addResearchElement("/lib/instances/research/trading/investment-strategies.c");
//    addChild("/lib/instances/research/trading/investment-strategies.c",
//        "/lib/instances/research/trading/credit-management.c");
//
//    addResearchElement("/lib/instances/research/trading/merchant-banking.c");
//    addChild("/lib/instances/research/trading/merchant-banking.c",
//        "/lib/instances/research/trading/investment-strategies.c");
//}
//
///////////////////////////////////////////////////////////////////////////////
//public void WarehouseOperations()
//{
//    addResearchElement("/lib/instances/research/trading/warehouse-management.c");
//    addChild("/lib/instances/research/trading/warehouse-management.c",
//        "/lib/instances/research/trading/cargo-management.c");
//
//    addResearchElement("/lib/instances/research/trading/inventory-optimization.c");
//    addChild("/lib/instances/research/trading/inventory-optimization.c",
//        "/lib/instances/research/trading/warehouse-management.c");
//
//    addResearchElement("/lib/instances/research/trading/storage-expansion.c");
//    addChild("/lib/instances/research/trading/storage-expansion.c",
//        "/lib/instances/research/trading/inventory-optimization.c");
//
//    addResearchElement("/lib/instances/research/trading/magical-storage.c");
//    addChild("/lib/instances/research/trading/magical-storage.c",
//        "/lib/instances/research/trading/storage-expansion.c");
//}
//
///////////////////////////////////////////////////////////////////////////////
//protected void Setup()
//{
//    Name("Commercial Operations");
//    Description("This research tree tracks the knowledge required for "
//        "successful trading and commercial operations");
//    Source("trading");
//    addPrerequisite("trade", 
//        (["type":"skill", "value" : 2]));
//    addResearchElement("/lib/instances/research/trading/basicCommerce.c");
//    TreeRoot("/lib/instances/research/trading/basicCommerce.c");
//
//    BasicTrading();
//    AdvancedTrading();
//    VehicleOperations();
//    FinancialOperations();
//    WarehouseOperations();
//}
