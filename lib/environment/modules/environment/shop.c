//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void addShop(string shop)
{
    object shopService = getService("shop");
    object shopObj = shopService->getShopObject(shop);
    if (shopObj)
    {
        if (!environmentalElements["shop"])
        {
            shopObj->Setup();
            shopService->generateInventory(shopObj);
            environmentalElements["shop"] = shopObj;
        }
        else
        {
            raise_error("ERROR in environment.c: a shop has already been "
                "assigned to this environment.\n");
        }
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid shop.\n", shop));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getShop()
{
    return environmentalElements["shop"];
}
