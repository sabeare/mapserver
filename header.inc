#==============================================================================
#
# header.map
# doel: algemene header-informatie dat voor alle map-bestanden gelijk is.
#
#==============================================================================
#
# naam                  datum         wijziging
# ------------------    ----------    -----------------------------------------
# Rob Kromwijk          07-09-2015    schepping
#
#==============================================================================



  #=============================================================================
  # MAP: debug
  #=============================================================================

  #CONFIG   "MS_ERRORFILE" "/srv/mapserver/ms_error.txt"
  #DEBUG    5

  #=============================================================================
  # MAP: algemeen
  #=============================================================================

  EXTENT      100000 450000 150000 500000
  UNITS       meters
  MAXSIZE     4000
  STATUS      ON

  # VPS06
  FONTSET     "fonts/fontlist.txt"
  SYMBOLSET   "symbols/symbollist.txt"
  # SHAPEPATH ""



  #=============================================================================
  # MAP: algemeen uitvoer
  #=============================================================================

  IMAGETYPE   agg_png

  WEB
    METADATA
      "ows_enable_request"           "*"
      "ows_srs"                      "EPSG:28992 EPSG:4326 EPSG:3857"
      "ows_feature_info_mime_type"   "application/json"
      "wms_format"                   "image/png"
      "wfs_encoding"                 "UTF-8"
      "wfs_maxfeatures"              "900000"
      "wfs_getfeature_formatlist"    "gml,geojson"

      # verplicht om aan de OGC standaard te voldoen:
      "ows_contactorganization"      "gemeente Amsterdam"
      "ows_contactperson"            "Basisinformatie"

    END
    IMAGEPATH    "/srv/mapserver/tmp_img/"
    IMAGEURL     "/ms_tmp/"
    BROWSEFORMAT "image/svg+xml"
  END

  PROJECTION
    "init=epsg:28992"
  END


  #-------------------------------------------------------------------
  # UITVOERFORMATEN
  #-------------------------------------------------------------------

  OUTPUTFORMAT
   NAME         agg_png
   DRIVER       "AGG/PNG"
   MIMETYPE     "image/png"
   IMAGEMODE    RGB
   EXTENSION    "png"
   FORMATOPTION "INTERLACE=OFF"
   FORMATOPTION "QUANTIZE_FORCE=ON"
  END

  OUTPUTFORMAT
    NAME "geojson"
    DRIVER "OGR/GEOJSON"
    MIMETYPE "application/json; subtype=geojson; charset=utf-8"
    FORMATOPTION "LCO:COORDINATE_PRECISION=7"
    FORMATOPTION "STORAGE=stream"
    FORMATOPTION "FORM=simple"
  END
