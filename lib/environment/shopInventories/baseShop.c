//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping list = ([]);
private string *ProhibitedTypes = ({});
private string Name = "Shop";
private string WelcomeMessage = "Welcome";
private string ShopType = "unknown";
private string ShopItemSubType = "all";
private int ItemsToGenerate = 15;
private string *equipmentTypes = ({ "armor", "instruments", "weapons" });
private mapping *specifiedItems = ({});
private mapping *individualItems = ({});

/////////////////////////////////////////////////////////////////////////////
public int itemListIsSpecified()
{
    return sizeof(specifiedItems) > 0;
}

/////////////////////////////////////////////////////////////////////////////
public void addInventoryItem(string type, string subType, string *items)
{
    specifiedItems += ({
        ([
            "type": type,
            "sub type": subType,
            "items": items
        ])
    });
}

/////////////////////////////////////////////////////////////////////////////
public void addItem(string fileName)
{
    object item;
    string error = catch (item = load_object(fileName));
    if (!error && (member(inherit_list(item), "lib/items/item.c") > -1))
    {
        individualItems += ({ fileName });
    }
    else
    {
        raise_error(error ? error :
            "ERROR baseShop: Items must inherit '/lib/items/item.c'");
    }
}

/////////////////////////////////////////////////////////////////////////////
public mapping *specifiedItems()
{
    return specifiedItems + ({});
}

/////////////////////////////////////////////////////////////////////////////
public string Type()
{
    return "shop";
}

/////////////////////////////////////////////////////////////////////////////
public nomask int shopSellsConsumables()
{
    return member(equipmentTypes, ShopType) == -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string name(string newName)
{
    if (newName && stringp(newName))
    {
        Name = newName;
    }
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string welcomeMessage(string newMessage)
{
    if (newMessage && stringp(newMessage))
    {
        WelcomeMessage = newMessage;
    }
    return WelcomeMessage;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string shopType(string newType)
{
    if (newType && stringp(newType))
    {
        ShopType = newType;
    }
    return ShopType;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string shopSubType(string newType)
{
    if (newType && stringp(newType))
    {
        ShopItemSubType = newType;
    }
    return ShopItemSubType;
}

/////////////////////////////////////////////////////////////////////////////
public int randomItemsToGenerate()
{
    return ItemsToGenerate;
}

/////////////////////////////////////////////////////////////////////////////
public void setRandomItemsToGenerate(int numberOfItems)
{
    ItemsToGenerate = numberOfItems;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int storeItem(object item, int isPermanent)
{
    int ret = 0;

    if (item && (member(inherit_list(item), "lib/items/item.c") > -1) &&
        !item->query("no sell"))
    {
        ret = 1;
        object dictionary = load_object("/lib/dictionaries/materialsDictionary.c");

        string key = item->query("quantity") ?
            program_name(item) : object_name(item);

        if (member(list, key))
        {
            list[key]["quantity"] += item->query("quantity");
        }
        else
        {
            list[key] = ([
                "name": item->query("name"),
                "description": item->long(1),
                "value": item->query("value"),
                "type": item->query("type"),
                "quantity": item->query("quantity"),
                "subType": dictionary->getBlueprintDetails(item, "subtype") ?
                    dictionary->getBlueprintDetails(item, "subtype") : "all",
                "quality": dictionary->getMaterialQualityFormatter(item),
                "summary": dictionary->getItemSummary(item),
                "data": item->query("all")
            ]);
        }
        if (item->query("enchanted") || item->query("craftsmanship"))
        {
            list[key]["do not prune"] = 1;
        }
        if (isPermanent)
        {
            list[key]["permanent"] = 1;
            list[key]["do not prune"] = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int buyItem(string key)
{
    int ret = 0;

    if (member(list, key))
    {
        ret = 1;

        if (list[key]["quantity"] > 0)
        {
            list[key]["quantity"]--;
        }

        if (!member(list[key], "permanent") && (list[key]["quantity"] < 1))
        {
            m_delete(list, key);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping storeInventory()
{
    return list + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void resetInventory()
{
    list = ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void initiateShopInteraction(object user)
{
    object selectorObj = clone_object("/lib/environment/shopInventories/shopSelector.c");
    move_object(selectorObj, user);
    selectorObj->setStore(this_object());
    selectorObj->setProhibitedTypes(ProhibitedTypes);
    selectorObj->registerEvent(this_object());
    selectorObj->initiateSelector(user);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorAborted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canPurchaseItem(object item)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void updateCustomItems()
{
    if (sizeof(individualItems))
    {
        foreach(string item in individualItems)
        {
            string keyCheck = 
                regreplace(item, "/*([^.]+)([.]c)*", "\\1", 1);

            string *inventoryItems = filter(m_indices(list),
                (: sizeof(regexp(({ $1 }), $2)) :), keyCheck);

            if (!sizeof(inventoryItems))
            {
                object itemObj = clone_object(item);

                itemObj->identify();
                storeItem(itemObj);
                destruct(itemObj);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public void updateShopInventory()
{
    int inventorySize = sizeof(list);
    if (inventorySize)
    {
        string *items = filter(m_indices(list),
            (: !member(list[$1], "do not prune") :));

        foreach(string item in items)
        {
            m_delete(list, item);
        }
    }

    inventorySize = sizeof(list);
    if (inventorySize < 15)
    {
        ItemsToGenerate = 16 - inventorySize + random(6);
        object dictionary = load_object("/lib/dictionaries/shopDictionary.c");

        if (shopSellsConsumables())
        {
            dictionary->generateConsumableItems(this_object(), 1);
        }
        else
        {
            dictionary->generateRandomItems(this_object());
        }
    }

    updateCustomItems();
}
