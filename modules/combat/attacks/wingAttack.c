inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("physical");
    addHitDictionary(({
        "bash", "slam", "slap", "pummel", "crush", "pound", "buffet", "smack",
        "assault" }));

    addSimileDictionary(({
        "smashing ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
        "the ##BodyPart##", "with a ##BodyPart##-whipping force" }));
        
    addMissMessage("##AttackerName## ##Infinitive::flap## ##AttackerPossessive##"
        " wings wildly!");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## with ##AttackerPossessive## wings.","1-50");
}




