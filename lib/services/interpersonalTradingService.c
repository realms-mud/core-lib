//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping offers = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask int transferable(object item, object owner)
{
    return objectp(item) && objectp(owner) &&
        environment(item) == owner &&
        function_exists("drop", item) && function_exists("query", item) &&
        !owner->isEquipped(item) && !item->query("undroppable") &&
        !item->query("ungettable") && !item->query("no sell");
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validExchange(object source, object target,
    object offered, object requested)
{
    return objectp(source) && objectp(target) && source != target &&
        function_exists("isRealizationOfLiving", source) &&
        function_exists("isRealizationOfLiving", target) &&
        source->isRealizationOfLiving() && target->isRealizationOfLiving() &&
        !source->isDead() && !target->isDead() &&
        environment(source) && environment(source) == environment(target) &&
        !source->isInCombatWith(target) &&
        offered != requested && transferable(offered, source) &&
        transferable(requested, target);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void cleanOffers()
{
    foreach(mixed target in m_indices(offers))
    {
        if (!objectp(target))
        {
            m_delete(offers, target);
        }
        else
        {
            foreach(mixed source in m_indices(offers[target]))
            {
                if (!objectp(source) ||
                    offers[target][source]["expires"] <= time())
                {
                    if (objectp(source))
                    {
                        tell_object(source, "Your trade offer has expired.\n");
                    }
                    m_delete(offers[target], source);
                }
            }
            if (!sizeof(offers[target]))
            {
                m_delete(offers, target);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int moveExchange(mapping offer)
{
    int ret = 0;
    object given = offer["offered"];
    object received = offer["requested"];
    if (!given->drop(1) && objectp(given) && !received->drop(1) &&
        objectp(received) && offer["source"]->canCarry(received) &&
        offer["target"]->canCarry(given))
    {
        move_object(given, offer["target"]);
        move_object(received, offer["source"]);
        ret = environment(given) == offer["target"] &&
            environment(received) == offer["source"];
    }
    if (!objectp(given) || !objectp(received))
    {
        raise_error("ERROR - trade transfer: A drop hook destroyed an item; "
            "that item cannot be restored.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int acceptOffer(object target, object source)
{
    int ret = 0;
    cleanOffers();
    if (member(offers, target) && member(offers[target], source))
    {
        mapping offer = offers[target][source];
        m_delete(offers[target], source);
        if (offer["expires"] > time() && validExchange(source, target,
            offer["offered"], offer["requested"]) &&
            (!target->isRealizationOfNpc() ||
                target->aiAcceptsTrade(source,
                    offer["offered"], offer["requested"])))
        {
            mapping context = ([
                "offered":program_name(offer["offered"]),
                "requested":program_name(offer["requested"])
            ]);
            mixed failure = catch(ret = moveExchange(offer); nolog);
            if (failure || !ret)
            {
                if (objectp(offer["offered"]) && objectp(source))
                {
                    move_object(offer["offered"], source);
                }
                if (objectp(offer["requested"]) && objectp(target))
                {
                    move_object(offer["requested"], target);
                }
                if (failure)
                {
                    raise_error("ERROR - trade transfer: " + failure + "\n");
                }
            }
            else
            {
                source->recordRelationshipInteraction(target, "trade.completed",
                    source->relationshipInteractionChanges("trade.completed"),
                    context);
                target->recordRelationshipInteraction(source, "trade.completed",
                    target->relationshipInteractionChanges("trade.completed"),
                    context);
                tell_object(source, "The trade is complete.\n");
                tell_object(target, "The trade is complete.\n");
            }
        }
    }
    if (!ret)
    {
        tell_object(target, "That trade cannot be completed. Check the offer, "
            "ownership, equipment, and carrying capacity.\n");
        if (objectp(source) && source != target)
        {
            tell_object(source, "The trade could not be completed.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int offerTrade(object source, object target,
    object offered, object requested)
{
    int ret = 0;
    cleanOffers();
    if (validExchange(source, target, offered, requested))
    {
        if (!member(offers, target))
        {
            offers[target] = ([]);
        }
        offers[target][source] = ([
            "source":source,
            "target":target,
            "offered":offered,
            "requested":requested,
            "expires":time() + 120
        ]);
        if (target->isRealizationOfNpc())
        {
            ret = acceptOffer(target, source);
            if (!ret)
            {
                tell_object(source, "They refuse or cannot complete that "
                    "trade. Check value, relationships, and capacity.\n");
            }
        }
        else
        {
            ret = 1;
            tell_object(source, "Your trade offer is awaiting acceptance.\n");
            tell_object(target, sprintf("%s offers %s for %s. "
                "Use 'accept trade from %s' or 'decline trade from %s'.\n",
                source->Name(), offered->query("name"),
                requested->query("name"), source->RealName(),
                source->RealName()));
        }
    }
    else
    {
        tell_object(source, "You cannot offer that trade. Both unequipped, "
            "transferable items and their owners must be here.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int declineOffer(object target, object source)
{
    int ret = 0;
    cleanOffers();
    if (member(offers, target) && member(offers[target], source))
    {
        m_delete(offers[target], source);
        tell_object(source, "Your trade offer was declined.\n");
        tell_object(target, "You decline the trade offer.\n");
        ret = 1;
    }
    else
    {
        tell_object(target, "There is no pending trade offer from them.\n");
    }
    return ret;
}
