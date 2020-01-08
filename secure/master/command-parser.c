//*****************************************************************************
// Taken nearly verbatim from LDMud's mudlib/master_skeleton.c
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public nomask string *parse_command_id_list()
{
    return ({ "one", "thing" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *parse_command_plural_id_list()
{
    return ({ "ones", "things", "them" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *parse_command_adjectiv_id_list()
{
    return ({ "iffish" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *parse_command_prepos_list()
{
    return ({ "in", "on", "under", "behind", "beside" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string parse_command_all_word()
{
    return "all";
}
