{
  "targets": [
    {
      "target_name": "srccrypt",
      "sources": [ "srccrypt.cc", "aes.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
