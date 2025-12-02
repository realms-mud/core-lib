//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public int testAddSpecification(string type, mixed value)
{
    return instantaneousActiveResearchItem::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public int testApplyBeneficialEffect(object initiator, object target)
{
    return instantaneousActiveResearchItem::applyBeneficialEffect(initiator, target);
}

/////////////////////////////////////////////////////////////////////////////
public int testApplyEffect(object initiator, object target)
{
    return instantaneousActiveResearchItem::applyEffect(initiator, target);
}
