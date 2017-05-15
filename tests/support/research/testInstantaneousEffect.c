//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousEffect.c";

private int useBeneficialEffect;
private int useApplyEffect;

/////////////////////////////////////////////////////////////////////////////
public void ToggleBeneficialEffect()
{
    useBeneficialEffect = !useBeneficialEffect;
}

/////////////////////////////////////////////////////////////////////////////
public void ToggleApplyEffect()
{
    useApplyEffect = !useApplyEffect;
}

/////////////////////////////////////////////////////////////////////////////
public int customFormula(object initiator)
{
    return 25;
}

/////////////////////////////////////////////////////////////////////////////
public int applyBeneficialEffect(object initiator, object target)
{
    return useBeneficialEffect;
}

/////////////////////////////////////////////////////////////////////////////
public int applyEffect(object initiator, object target)
{
    return useApplyEffect;
}

/////////////////////////////////////////////////////////////////////////////
public int testApplyFormula(object initiator, string type)
{
    return instantaneousEffect::applyFormula(initiator, type);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddInstantaneousSpecification(string type, mixed value)
{
    return instantaneousEffect::addInstantaneousSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public object testGetTarget(object owner, string command)
{
    return baseCommand::getTarget(owner, command);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnSelf(object owner, string researchName)
{
    return instantaneousEffect::executeOnSelf(owner, researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    return instantaneousEffect::executeOnTarget(unparsedCommand, owner, researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteInArea(object owner, string researchName)
{
    return instantaneousEffect::executeInArea(owner, researchName);
}

