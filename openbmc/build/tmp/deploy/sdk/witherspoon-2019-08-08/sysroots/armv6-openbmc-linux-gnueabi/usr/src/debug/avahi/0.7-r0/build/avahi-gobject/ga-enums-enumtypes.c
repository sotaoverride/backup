
/* This file is generated by glib-mkenums, do not modify it. This code is
 * licensed under the same license as the containing project. Note that it links
 * to GLib, so must comply with the LGPL linking clauses. */

#include <ga-enums-enumtypes.h>
#include <ga-enums.h>

/* enumerations from "../../avahi-0.7/avahi-gobject/ga-enums.h" */
GType ga_protocol_get_type(void)
{
    static GType etype = 0;
    if (etype == 0)
    {
        static const GEnumValue values[] = {
            {GA_PROTOCOL_INET, "GA_PROTOCOL_INET", "GA_PROTOCOL_INET"},
            {GA_PROTOCOL_INET6, "GA_PROTOCOL_INET6", "GA_PROTOCOL_INET6"},
            {GA_PROTOCOL_UNSPEC, "GA_PROTOCOL_UNSPEC", "GA_PROTOCOL_UNSPEC"},
            {0, NULL, NULL}};
        etype = g_enum_register_static("GaProtocol", values);
    }
    return etype;
}
GType ga_lookup_result_flags_get_type(void)
{
    static GType etype = 0;
    if (etype == 0)
    {
        static const GEnumValue values[] = {
            {GA_LOOKUP_RESULT_CACHED, "GA_LOOKUP_RESULT_CACHED",
             "GA_LOOKUP_RESULT_CACHED"},
            {GA_LOOKUP_RESULT_WIDE_AREA, "GA_LOOKUP_RESULT_WIDE_AREA",
             "GA_LOOKUP_RESULT_WIDE_AREA"},
            {GA_LOOKUP_RESULT_MULTICAST, "GA_LOOKUP_RESULT_MULTICAST",
             "GA_LOOKUP_RESULT_MULTICAST"},
            {GA_LOOKUP_RESULT_LOCAL, "GA_LOOKUP_RESULT_LOCAL",
             "GA_LOOKUP_RESULT_LOCAL"},
            {GA_LOOKUP_RESULT_OUR_OWN, "GA_LOOKUP_RESULT_OUR_OWN",
             "GA_LOOKUP_RESULT_OUR_OWN"},
            {GA_LOOKUP_RESULT_STATIC, "GA_LOOKUP_RESULT_STATIC",
             "GA_LOOKUP_RESULT_STATIC"},
            {0, NULL, NULL}};
        etype = g_enum_register_static("GaLookupResultFlags", values);
    }
    return etype;
}
GType ga_lookup_flags_get_type(void)
{
    static GType etype = 0;
    if (etype == 0)
    {
        static const GEnumValue values[] = {
            {GA_LOOKUP_NO_FLAGS, "GA_LOOKUP_NO_FLAGS", "GA_LOOKUP_NO_FLAGS"},
            {GA_LOOKUP_USE_WIDE_AREA, "GA_LOOKUP_USE_WIDE_AREA",
             "GA_LOOKUP_USE_WIDE_AREA"},
            {GA_LOOKUP_USE_MULTICAST, "GA_LOOKUP_USE_MULTICAST",
             "GA_LOOKUP_USE_MULTICAST"},
            {GA_LOOKUP_NO_TXT, "GA_LOOKUP_NO_TXT", "GA_LOOKUP_NO_TXT"},
            {GA_LOOKUP_NO_ADDRESS, "GA_LOOKUP_NO_ADDRESS",
             "GA_LOOKUP_NO_ADDRESS"},
            {0, NULL, NULL}};
        etype = g_enum_register_static("GaLookupFlags", values);
    }
    return etype;
}
GType ga_resolver_event_get_type(void)
{
    static GType etype = 0;
    if (etype == 0)
    {
        static const GEnumValue values[] = {
            {GA_RESOLVER_FOUND, "GA_RESOLVER_FOUND", "GA_RESOLVER_FOUND"},
            {GA_RESOLVER_FAILURE, "GA_RESOLVER_FAILURE", "GA_RESOLVER_FAILURE"},
            {0, NULL, NULL}};
        etype = g_enum_register_static("GaResolverEvent", values);
    }
    return etype;
}
GType ga_browser_event_get_type(void)
{
    static GType etype = 0;
    if (etype == 0)
    {
        static const GEnumValue values[] = {
            {GA_BROWSER_NEW, "GA_BROWSER_NEW", "GA_BROWSER_NEW"},
            {GA_BROWSER_REMOVE, "GA_BROWSER_REMOVE", "GA_BROWSER_REMOVE"},
            {GA_BROWSER_CACHE_EXHAUSTED, "GA_BROWSER_CACHE_EXHAUSTED",
             "GA_BROWSER_CACHE_EXHAUSTED"},
            {GA_BROWSER_ALL_FOR_NOW, "GA_BROWSER_ALL_FOR_NOW",
             "GA_BROWSER_ALL_FOR_NOW"},
            {GA_BROWSER_FAILURE, "GA_BROWSER_FAILURE", "GA_BROWSER_FAILURE"},
            {0, NULL, NULL}};
        etype = g_enum_register_static("GaBrowserEvent", values);
    }
    return etype;
}

/* Generated data ends here */
