//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    ::init();
    setDamageType("physical");
    addHitDictionary(({
        "stomp", "trample", "pummel", "pound", "smack", "assault" }));

    addSimileDictionary(({
        "smashing into ##TargetPossessive## ##BodyPart##", "repeatedly in "
        "the ##BodyPart##" }));
        
    addMissMessage("##AttackerName## ##Infinitive::rear## up wildly and "
        "##Infinitive::paw## at the air with ##AttackerPossessive## hooves.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## with ##AttackerPossessive## hooves.","1-50");
}




