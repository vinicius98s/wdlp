const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const CopyPlugin = require("copy-webpack-plugin");
const ImageMinimizerPlugin = require("image-minimizer-webpack-plugin");

const outputDir = path.resolve(__dirname, "./dist");

module.exports = {
  entry: "./src/Index.bs.js",
  mode: process.env.NODE_ENV === "production" ? "production" : "development",
  optimization: {
    usedExports: true,
  },
  module: {
    rules: [
      {
        test: /\.(png|jpe?g|gif)$/i,
        use: [
          {
            loader: "file-loader",
          },
        ],
      },
    ],
  },
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: 8080,
    historyApiFallback: true,
  },
  output: {
    path: outputDir,
    filename: "index.js",
  },
  plugins: [
    new HtmlWebpackPlugin({ template: "./public/index.html" }),
    // new ImageMinimizerPlugin({
    //   minimizerOptions: {
    //     plugins: [["optipng", { optimizationLevel: 9 }]],
    //   },
    // }),
    new CopyPlugin({
      patterns: [
        {
          from: "./public/assets",
          to: path.resolve(outputDir, "assets"),
        },
      ],
    }),
  ],
};
