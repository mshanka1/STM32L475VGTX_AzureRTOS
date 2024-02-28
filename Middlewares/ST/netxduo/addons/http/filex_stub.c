
#include "tx_api.h"
#include "filex_stub.h"

/* None of these functions should ever be called, but we need to stub them out because the HTTP server uses them internally  */

UINT        fx_directory_attributes_read(FX_MEDIA *media_ptr, CHAR *directory_name, UINT *attributes_ptr)
{
  return 0;
}

UINT        fx_directory_attributes_set(FX_MEDIA *media_ptr, CHAR *directory_name, UINT attributes)
{
  return 0;
}


UINT        fx_directory_create(FX_MEDIA *media_ptr, CHAR *directory_name)
{
  return 0;
}


UINT        fx_directory_delete(FX_MEDIA *media_ptr, CHAR *directory_name)
{
  return 0;
}


UINT        fx_directory_rename(FX_MEDIA *media_ptr, CHAR *old_directory_name, CHAR *new_directory_name)
{
  return 0;
}


UINT        fx_directory_first_entry_find(FX_MEDIA *media_ptr, CHAR *directory_name)
{
  return 0;
}


UINT        fx_directory_first_full_entry_find(FX_MEDIA *media_ptr, CHAR *directory_name, UINT *attributes,
                ULONG *size, UINT *year, UINT *month, UINT *day, UINT *hour, UINT *minute, UINT *second)
{
  return 0;
}


UINT        fx_directory_next_entry_find(FX_MEDIA *media_ptr, CHAR *directory_name)
{
  return 0;
}


UINT        fx_directory_next_full_entry_find(FX_MEDIA *media_ptr, CHAR *directory_name, UINT *attributes,
                ULONG *size, UINT *year, UINT *month, UINT *day, UINT *hour, UINT *minute, UINT *second)
{
  return 0;
}


UINT        fx_directory_name_test(FX_MEDIA *media_ptr, CHAR *directory_name)
{
  return 0;
}


UINT        fx_directory_information_get(FX_MEDIA *media_ptr, CHAR *directory_name, UINT *attributes, ULONG *size,
                                        UINT *year, UINT *month, UINT *day, UINT *hour, UINT *minute, UINT *second)
{
  return 0;
}


UINT        fx_directory_default_set(FX_MEDIA *media_ptr, CHAR *new_path_name)
{
  return 0;
}


UINT        fx_directory_default_get(FX_MEDIA *media_ptr, CHAR **return_path_name)
{
  return 0;
}




UINT        fx_file_best_effort_allocate(FX_FILE *file_ptr, ULONG size, ULONG *actual_size_allocated)
{
  return 0;
}



UINT        fx_file_create(FX_MEDIA *media_ptr, CHAR *file_name)
{
  return 0;
}



UINT        fx_file_delete(FX_MEDIA *media_ptr, CHAR *file_name)
{
  return 0;
}



UINT        fx_file_rename(FX_MEDIA *media_ptr, CHAR *old_file_name, CHAR *new_file_name)
{
  return 0;
}



UINT        fx_file_attributes_set(FX_MEDIA *media_ptr, CHAR *file_name, UINT attributes)
{
  return 0;
}



UINT        fx_file_attributes_read(FX_MEDIA *media_ptr, CHAR *file_name, UINT *attributes_ptr)
{
  return 0;
}



UINT        fx_file_open(FX_MEDIA *media_ptr, FX_FILE *file_ptr, CHAR *file_name,
                UINT open_type)
{
  return 0;
}



UINT        fx_file_close(FX_FILE *file_ptr)
{
  return 0;
}



UINT        fx_file_read(FX_FILE *file_ptr, VOID *buffer_ptr, ULONG request_size, ULONG *actual_size)
{
  return 0;
}



UINT        fx_file_write(FX_FILE *file_ptr, VOID *buffer_ptr, ULONG size)
{
  return 0;
}



UINT        fx_file_allocate(FX_FILE *file_ptr, ULONG size)
{
  return 0;
}



UINT        fx_file_relative_seek(FX_FILE *file_ptr, ULONG byte_offset, UINT seek_from)
{
  return 0;
}



UINT        fx_file_seek(FX_FILE *file_ptr, ULONG byte_offset)
{
  return 0;
}



UINT        fx_file_truncate(FX_FILE *file_ptr, ULONG size)
{
  return 0;
}



UINT        fx_file_truncate_release(FX_FILE *file_ptr, ULONG size)
{
  return 0;
}


