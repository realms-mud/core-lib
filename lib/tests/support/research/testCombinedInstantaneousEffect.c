//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/combinedInstantaneousEffect.c";

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
public int applyBeneficialEffect(object initiator, string *combo)
{
    return useBeneficialEffect;
}

/////////////////////////////////////////////////////////////////////////////
public int applyEffect(object initiator, object target, string *combo)
{
    return useApplyEffect;
}

/////////////////////////////////////////////////////////////////////////////
public int testApplyFormula(object initiator, int amount, string type)
{
    return combinedInstantaneousEffect::applyFormula(initiator, amount, type);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddInstantaneousSpecification(string type, mixed value)
{
    return combinedInstantaneousEffect::addInstantaneousSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public object testGetTarget(object owner, string command)
{
    return baseCommand::getTarget(owner, command);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnSelf(string unparsedCommand, object owner, 
    string researchName)
{
    return combinedInstantaneousEffect::executeOnSelf(unparsedCommand, owner,
        researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    return combinedInstantaneousEffect::executeOnTarget(unparsedCommand, owner,
        researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteInArea(string unparsedCommand, object owner, 
    string researchName)
{
    return combinedInstantaneousEffect::executeInArea(unparsedCommand, owner,
        researchName);
}

/////////////////////////////////////////////////////////////////////////////
public object *testGetCombinationList(string unparsedCommand,
    object owner)
{
    return combinedInstantaneousEffect::getCombinationList(unparsedCommand,
        owner);
}
