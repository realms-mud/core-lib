//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/effectModifier.c";

private int useSpecialModifier;

/////////////////////////////////////////////////////////////////////////////
public void ToggleSpecialModifier()
{
    useSpecialModifier = !useSpecialModifier;
}

/////////////////////////////////////////////////////////////////////////////
public float specialModifier()
{
    return useSpecialModifier ? 2.0 : effectModifier::specialModifier();
}

/////////////////////////////////////////////////////////////////////////////
public int testIsValidModifier(mapping modifier)
{
    return effectModifier::isValidModifier(modifier);
}

/////////////////////////////////////////////////////////////////////////////
public int testApplyModifiers(int value, object initiator, mapping *modifiers)
{
    return effectModifier::applyModifiers(value, initiator, modifiers);
}
